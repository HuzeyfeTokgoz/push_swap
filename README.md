# Push_swap

[cite_start]*This project has been created as part of the 42 curriculum by hutokgoz and [partner_login].* [cite: 397]

## 📋 Description
[cite_start]**Push_swap**, sınırlı operasyon setine sahip iki yığın (stack a ve b) kullanarak verileri en az hamleyle sıralamayı hedefleyen bir algoritmik projedir[cite: 3, 105]. [cite_start]Proje, algoritmik karmaşıklığı (Big-O) somut bir şekilde anlamayı ve veri setinin düzensizlik durumuna göre en uygun stratejiyi seçmeyi amaçlar[cite: 111, 114].

## 🛠️ Instructions

### Compilation
[cite_start]Proje, sağlanan Makefile kullanılarak standart `cc` ve gerekli flaglar (`-Wall -Wextra -Werror`) ile derlenir[cite: 36, 253]:
```bash
# Ana programı derlemek için
make

# Bonus (checker) programını derlemek için
make bonus
```

### Execution
[cite_start]Program, bir tam sayı listesi alır ve bunları sıralamak için gereken operasyon dizisini ekrana basar[cite: 106, 257].
```bash
./push_swap 3 2 10 0
```

**Opsiyonel Flaglar:**
* [cite_start]`--simple`: $O(n^2)$ algoritmasını zorlar[cite: 260].
* [cite_start]`--medium`: $O(n\sqrt{n})$ algoritmasını zorlar[cite: 261].
* [cite_start]`--complex`: $O(n \log n)$ algoritmasını zorlar[cite: 262].
* [cite_start]`--adaptive`: Düzensizlik miktarına göre otomatik strateji seçer (Varsayılan)[cite: 263, 264].
* [cite_start]`--bench`: Sıralama sonrası performans metriklerini `stderr` üzerinden görüntüler[cite: 278, 283].

---

## 🚀 Algorithms & Complexity Analysis

[cite_start]Proje kapsamında dört farklı strateji uygulanmıştır[cite: 151, 276]:

### 1. Simple Algorithm ($O(n^2)$)
* [cite_start]**Teknik:** En küçük sayıyı bulup `stack b`'ye aktarma (Selection Sort adaptasyonu)[cite: 184, 186].
* **Karmaşıklık:** En kötü durumda $n$ eleman için her seferinde tüm yığın taranır ($n + (n-1) + ...$).
* **Kullanım:** Çok küçük veri setleri veya düşük karmaşıklık gerektiren durumlar.

### 2. Medium Algorithm ($O(n\sqrt{n})$)
* [cite_start]**Teknik:** Yığını $\sqrt{n}$ büyüklüğünde parçalara (chunks) bölerek `stack b`'ye aktarma[cite: 189].
* **Karmaşıklık:** Elemanlar belirli aralıklara göre gruplanır, bu da her eleman için gereken rotasyon sayısını azaltır.
* **Kullanım:** 100-500 arası orta ölçekli veri setleri.

### 3. Complex Algorithm ($O(n \log n)$)
* [cite_start]**Teknik:** Radix Sort (LSD) adaptasyonu[cite: 195].
* **Karmaşıklık:** Sayıların bit değerlerine göre (indexlenmiş haliyle) işlem yapılır. [cite_start]Her bit için $n$ operasyon yapılır; toplamda $n \times \text{max\_bits}$ operasyon sürer[cite: 193].
* **Kullanım:** Çok büyük veya tamamen rastgele veri setleri.

### 4. Custom Adaptive Algorithm
[cite_start]Bu algoritma, yığının başlangıçtaki **disorder (düzensizlik)** oranını ölçerek en verimli yöntemi seçer[cite: 200].

#### Disorder Metric & Thresholds
[cite_start]Düzensizlik, yığındaki tüm olası çiftler arasındaki "hatalı" (büyük sayının küçükten önce gelmesi) sıralamaların toplam çift sayısına oranıdır[cite: 161, 175]:
$$Disorder = \frac{Mistakes}{Total\ Pairs}$$

* [cite_start]**Low Disorder ($< 0.2$):** Simple Algorithm kullanılır ($O(n^2)$ hedefi)[cite: 203].
* [cite_start]**Medium Disorder ($0.2 \le x < 0.5$):** Medium Algorithm kullanılır ($O(n\sqrt{n})$ hedefi)[cite: 204].
* [cite_start]**High Disorder ($\ge 0.5$):** Complex Algorithm kullanılır ($O(n \log n)$ hedefi)[cite: 205].

---

## 🏁 Performance Targets
[cite_start]Proje, 42 standartlarına göre aşağıdaki operasyon sınırlarını karşılamaktadır[cite: 381]:
* [cite_start]**100 Sayı:** < 700 operasyon (Excellent)[cite: 385].
* [cite_start]**500 Sayı:** < 5500 operasyon (Excellent)[cite: 389].

---

## 🤝 Contributions
* [cite_start]**hutokgoz:** `push_swap` ana mantığı, `disorder` hesaplama, `Simple` ve `Medium` algoritmaların implementasyonu, `benchmark` modu ve hata yönetimi[cite: 122].
* [cite_start]**[partner_login]:** `Complex` (Radix) algoritması, `checker` (bonus) programı, veri ayrıştırma (parser) ve stack operasyonlarının optimizasyonu[cite: 122, 453].

## 📚 Resources & AI Disclosure
* [cite_start]**Resources:** 42 Common Core verimlilik tabloları, "The Art of Computer Programming" (Donald Knuth)[cite: 14].
* [cite_start]**AI Usage:** Algoritmik mantık taslaklarının oluşturulmasında, özellikle `disorder` metriğinin matematiksel modellemesinde ve uç durum test senaryolarının belirlenmesinde AI araçlarından destek alınmıştır[cite: 400]. [cite_start]Üretilen tüm kodlar manuel olarak incelenmiş, Norm standartlarına göre revize edilmiş ve mantığı ekip tarafından doğrulanmıştır[cite: 67, 71, 95].

---

**Would you like me to refine the "Internal Techniques" section with more specific details from your `ps_medium_alg.c` code?**