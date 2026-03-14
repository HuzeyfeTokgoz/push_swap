#!/bin/bash

# Renkler
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m'

# Rastgele Sayı Üretici (Normal)
gen_random() { shuf -i 1-10000 -n $1 | tr '\n' ' '; }

# Düşük Disorder Üretici (~0.2 için sıralı listenin %10'unu karıştırır)
gen_low_disorder() {
    seq 1 $1 > tmp_list
    count=$(($1 / 10))
    for i in $(seq 1 $count); do
        line1=$((RANDOM % $1 + 1))
        line2=$((RANDOM % $1 + 1))
        val1=$(sed -n "${line1}p" tmp_list)
        val2=$(sed -n "${line2}p" tmp_list)
        sed -i "${line1}s/.*/$val2/" tmp_list
        sed -i "${line2}s/.*/$val1/" tmp_list
    done
    cat tmp_list | tr '\n' ' '
    rm tmp_list
}

run_test() {
    local flag=$1
    local size=$2
    local type=$3
    local args=""
    
    if [ "$type" == "low" ]; then args=$(gen_low_disorder $size); else args=$(gen_random $size); fi
    
    echo -e "${BLUE}Testing $flag | Size: $size | Type: $type${NC}"
    
    # Adım Sayısı ve Checker Kontrolü
    OPS=$(./push_swap $flag $args | wc -l)
    CHECK=$(./push_swap $flag $args | ./checker_linux $args)
    
    # Benchmark verisi (Disorder görmek için)
    DISORDER=$(./push_swap --bench $flag $args 2>&1 | grep "disorder" | awk '{print $3}')
    
    echo -e "Result: $CHECK | Steps: $OPS | Disorder: $DISORDER"
    echo "-----------------------------------------------"
}

echo -e "${GREEN}--- PUSH_SWAP STRATEGY ANALYSIS ---${NC}"

# 1. SIMPLE ALGORITMA TESTLERİ (O(n^2))
# Simple için asıl kriter: Disorder < 0.2
run_test "--simple" 100 "low"    # İdeal durum
run_test "--simple" 100 "random" # Zorlu durum

# 2. MEDIUM ALGORITMA TESTLERİ (O(n*sqrt(n)))
# Hedef: 100 sayı < 1500, 500 sayı < 8000
run_test "--medium" 100 "random"
run_test "--medium" 500 "random"

# 3. COMPLEX ALGORITMA TESTLERİ (O(n log n))
# Hedef: 100 sayı < 700, 500 sayı < 5500
run_test "--complex" 100 "random"
run_test "--complex" 500 "random"

# 4. ADAPTIVE TESTİ (Otomatik Seçim)
run_test "--adaptive" 500 "random"