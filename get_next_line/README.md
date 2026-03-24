*This project has been created as part of the 42 curriculum by hutokgoz.*

# Get Next Line

## Description

**Get Next Line**, C programlama dilinde dosya işlemlerini, bellek yönetimini ve statik değişkenlerin yaşam döngüsünü derinlemesine kavramak amacıyla geliştirdiğim temel bir projedir. Standart kütüphanedeki dosya okuma fonksiyonlarının aksine, bu proje herhangi bir dosya tanımlayıcısından (file descriptor) **satır satır** okuma yapabilen bir fonksiyon mimarisini hedefler.

Projenin temel amacı, dosya boyutu veya satır uzunluğu ne olursa olsun (ister 1 byte ister 10 milyon byte `BUFFER_SIZE` ile) verimli ve stabil çalışan bir algoritma kurmaktır.

Bu projede, bellek sızıntılarını önlemek ve veri bütünlüğünü korumak için **"Oku - Ayıkla - Temizle" (Read-Extract-Clean)** prensibine dayanan 3 aşamalı modüler bir yapı tercih ettim:
1.  **Read:** Dosyayı tampon bellek boyutunda okuyup statik bir değişkende biriktirmek.
2.  **Extract:** Biriken veriden sadece ilk satırı izole edip kullanıcıya döndürmek.
3.  **Clean:** Statik depoda kalan işlenmiş veriyi temizleyip bir sonraki çağrıya hazırlamak.

## Instructions

### Compilation (Derleme)
Proje, derleme aşamasında tampon boyutunun (Buffer Size) dışarıdan belirlenmesine olanak tanır. Projeyi test etmek veya derlemek için aşağıdaki bayrakları kullanmanız gerekmektedir:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c

```

*(Not: `42` yerine ihtiyacınıza göre `1`, `1024` veya `9999` gibi değerler verebilirsiniz.)*

### Execution (Çalıştırma)

Derleme işlemi tamamlandıktan sonra oluşan çalıştırılabilir dosyayı şu şekilde çalıştırabilirsiniz:

```bash
./a.out
```

### Usage (Kullanım)

Fonksiyonu kendi projenizde kullanmak için `get_next_line.h` başlık dosyasını projenize dahil etmeniz (include) ve kaynak dosyaları projenizle birlikte derlemeniz yeterlidir.

## Resources

Bu projenin geliştirilmesinde aşağıdaki kaynaklardan ve araçlardan faydalanılmıştır.

### References (Referanslar)

* **Linux Man Pages:** `read(2)`, `malloc(3)`, `free(3)`, `open(2)` sistem çağrılarının davranışlarını ve dönüş değerlerini incelemek için.
* **GNU C Library Documentation:** Standart I/O fonksiyonlarının bellek yönetimi stratejilerini ve dosya tanımlayıcı (File Descriptor) mantığını anlamak için.

### AI Usage (Yapay Zeka Kullanımı)
Proje geliştirme sürecinde Yapay Zeka araçlarından, öğrenme sürecini destekleyici bir "Eğitim Asistanı" olarak faydalanılmıştır:

* Konsept Analizi: Statik değişkenlerin (static variables) yaşam döngüsü ve bellekteki kalıcılığının teorik olarak incelenmesi.

* Dokümantasyon: Standart kütüphane fonksiyonlarının (read gibi) parametre yapıları ve dönüş değerleri (return values) hakkında hızlı referans bilgisi edinilmesi.

* Senaryo Üretimi: Fonksiyonun karşılaşabileceği uç durumların (örneğin; dosyanın \n ile bitmemesi veya boş dosya okunması) teorik olarak listelenmesi.

## ⭐️ Bonus Bölüm (Bonus Part)

Proje, zorunlu gereksinimlere ek olarak Bonus bölümünü de kapsamaktadır. Bu bölüm şu özellikleri ekler:
* **Tek Statik Değişken:** Tüm mantık, tek bir statik pointer dizisi (array of pointers) kullanılarak yönetilmiştir.
* **Çoklu Dosya Yönetimi:** Fonksiyon, aynı anda birden fazla dosya tanımlayıcısını (file descriptor) yönetebilir. (Örneğin; önce fd 3'ten, sonra fd 4'ten, sonra tekrar fd 3'ten kaldığı yerden okuma yapabilir).

### Bonus Derleme (Compilation)
Bonus dosyalarını derlemek için şu komutu kullanabilirsiniz:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
```
*Projenin tüm algoritma kurgusu, kod yazımı ve mantık akışı tarafımdan gerçekleştirilmiştir.*