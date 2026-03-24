# push_swap

*This project has been created as part of the 42 curriculum by hutokgoz and mburdurl.*

## Açıklama
Bu proje, sınırlı bir operasyon seti kullanarak `stack a` içindeki sayıları en az hamleyle sıralamayı amaçlar. İki yığın (a ve b) kullanarak, veri setinin düzensizlik durumuna göre en uygun algoritmayı seçmeyi ve Big-O karmaşıklığını öğrenmeyi hedefledik.

## Talimatlar

### Derleme
Standart Makefile kurallarıyla derlenir:
```bash
make all    # push_swap binary'sini oluşturur
make bonus  # checker programını oluşturur
```

### Kullanım
Program, sıralanacak sayıları parametre olarak alır:
```bash
./push_swap 4 67 3 87 23
```

**Opsiyonel Flaglar:**
* `--simple`: $O(n^2)$ algoritmasını zorlar.
* `--medium`: $O(n\sqrt{n})$ algoritmasını zorlar.
* `--complex`: $O(n \log n)$ algoritmasını zorlar.
* `--adaptive`: Düzensizliğe göre otomatik seçim yapar (varsayılan).
* `--bench`: Hamle sayısı ve operasyon detaylarını `stderr` üzerinden gösterir.

## Algoritmalar ve Seçim Gerekçeleri
Projede her durum için farklı bir yaklaşım belirledik:

1.  **Simple ($O(n^2)$):** Küçük sayılar için en küçüğü bulup b'ye atma mantığıyla çalışır.
2.  **Medium ($O(n\sqrt{n})$):** Sayıları belirli aralıklarla (chunks) b'ye atıp geri çekerken sıralayan bir yöntem kullandık.
3.  **Complex ($O(n \log n)$):** Çok büyük veri setleri için bit manipülasyonu yapan Radix Sort adaptasyonudur.
4.  **Adaptive:** Başlangıçtaki düzensizlik (disorder) oranına göre otomatik karar verir.

**Disorder Eşik Değerlerimiz:**
* **Disorder < 0.2:** Low disorder, Simple algoritma.
* **0.2 ≤ Disorder < 0.5:** Medium disorder, Medium algoritma.
* **Disorder ≥ 0.5:** High disorder, Complex algoritma.

## Contributions
* **hutokgoz:** `disorder` metriğinin kodlanması, `simple` ve `medium` algoritmaların implementasyonu ve benchmark modunun geliştirilmesi.

* **mburdurl:** `complex` algoritması, `parser` ve `checker` programının kodlanması.

## Kaynaklar Ve AI Kullanımı
* **Kaynaklar:** 42 subject PDF'i ve algoritma dökümanları kullanıldı.

* **AI Kullanımı:** Proje tasarımı sırasında düzensizlik oranının matematiksel modellemesi ve `medium` algoritmadaki chunk boyutlarının belirlenmesi aşamalarında AI araçlarından mantık desteği alınmıştır. Üretilen tüm mantık yapıları manuel olarak koda dökülmüş ve test edilmiştir.