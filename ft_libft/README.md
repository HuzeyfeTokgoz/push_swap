*This project has been created as part of the 42 curriculum by hutokgoz*

# Libft

## Açıklama (Description)
Bu proje, C programlama dilinde temel fonksiyonları içeren bir kütüphane oluşturmayı amaçlamaktadır. Standart C kütüphanesindeki (libc) fonksiyonların işleyişini bizzat kodlayarak anlamayı ve sonraki projelerde kullanılabilecek genel amaçlı araçlar geliştirmeyi hedefler. Kütüphane, bellek yönetimi, karakter kontrolü, dize manipülasyonu ve bağlı liste (linked list) işlemleri gibi temel yapı taşlarını içerir.

### Kütüphane İçeriği
Oluşturulan libft.a kütüphanesi üç ana bölümden oluşur:

### Bölüm 1 - Libc Fonksiyonları: 
ft_strlen, ft_memset, ft_atoi gibi standart fonksiyonların, orijinal davranışlarına sadık kalınarak yeniden yazılmış halleridir.

### Bölüm 2 - Ek Fonksiyonlar:
ft_substr, ft_strjoin, ft_split ve ft_itoa gibi libc'de bulunmayan veya farklı formda olan yardımcı fonksiyonlardır.

### Bölüm 3 - Linked List:
t_list yapısını kullanarak veri listeleri oluşturmayı, eklemeyi ve silmeyi sağlayan fonksiyon setidir.

## Talimatlar (Instructions)

### Derleme
Proje, kaynak dosyalarını -Wall -Wextra -Werror bayraklarını kullanarak derleyen bir Makefile içerir.

Kütüphaneyi oluşturmak için terminale şu komutu yazın: **make**

Bu işlem, ana dizinde libft.a dosyasını oluşturacaktır.

Kütüphane kullanımı: `#include "libft.a"`

### Makefile Kuralları
`make` / `make all`: fonksiyonları derler.

`make clean`: Nesne (.o) dosyalarını siler.

`make fclean`: Nesne dosyalarını ve libft.a dosyasını siler.

`make re`: Tüm projeyi temizleyip yeniden derler.

## Kaynaklar (Resources)

### Kullanılan Kütüphaneler
`stdlib.h` = size_t NULL malloc free kullanımı için kullanıldı.

`unistd.h` = write fonksiyonu için kullanıldı.

`fcntl.h` = open fonksiyonu için kullanıldı.

### Dokümantasyon:
Standart libc fonksiyonları için Linux man sayfaları kullanılmıştır.

### Yapay Zeka Kullanımı: 

#### Görevler:
AI, özellikle ft_split fonksiyonundaki bellek sızıntılarını (memory leaks) tespit etmek ve bağlı liste mantığını görselleştirmek için kullanılmıştır.

#### Bölümler: 
Projenin ikinci bölümündeki karmaşık algoritma yapılarını anlamak amacıyla destek alınmıştır.

#### Kontrol:
42 Norm kurallarına ve proje gereksinimlerine uygun şekilde tarafımca manuel olarak düzenlenmiştir.