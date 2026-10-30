// Java util kütüphanesini projeye dahil edelim
import java.util.*;

// Tarih işlemleri için LocalDate sınıfını dahil edelim
import java.time.LocalDate;

// Oda Class

// Oda adında sınıf oluşturalım
class Oda {

    // Oda numarası
    int odaNumarasi;

    // Oda tipi
    String tip;

    // Constructor metodunu kullanalım
    Oda(int odaNumarasi, String tip) {

        // Gelen oda numarasını atar
        this.odaNumarasi = odaNumarasi;

        // Gelen oda tipini atar
        this.tip = tip;
    }

    // Oda bilgilerini yazdıralım
    public String toString() {

        return "Oda No: " + odaNumarasi + " | Tip: " + tip;
    }
}

// Musteri Class

// Müşteri adında sınıf oluşturalım
class Musteri {

    // Müşteri ID
    int musteriId;

    // Müşteri adı
    String isim;

    // Telefon
    String telefon;

    // Constructor
    Musteri(int musteriId, String isim, String telefon) {

        this.musteriId = musteriId;
        this.isim = isim;
        this.telefon = telefon;
    }

    public String toString() {

        return "Musteri ID: " + musteriId +
                " | Isim: " + isim +
                " | Telefon: " + telefon;
    }
}

// Rezervasyon Class

// Rezervasyon sınıfı
class Rezervasyon {

    // Rezervasyon ID
    int rezervasyonId;

    // Müşteri
    Musteri musteri;

    // Oda
    Oda oda;

    // Giriş tarihi
    LocalDate girisTarihi;

    // Çıkış tarihi
    LocalDate cikisTarihi;

    // Constructor
    Rezervasyon(int rezervasyonId,
                 Musteri musteri,
                 Oda oda,
                 LocalDate girisTarihi,
                 LocalDate cikisTarihi) {

        this.rezervasyonId = rezervasyonId;
        this.musteri = musteri;
        this.oda = oda;
        this.girisTarihi = girisTarihi;
        this.cikisTarihi = cikisTarihi;
    }

    public String toString() {

        return "Rezervasyon ID: " + rezervasyonId +
                " | Musteri: " + musteri.isim +
                " | Oda: " + oda.odaNumarasi +
                " | Tip: " + oda.tip +
                " | Giris: " + girisTarihi +
                " | Cikis: " + cikisTarihi;
    }
}

// Node Class

// Bağlı listedeki düğümü temsil eder
class Node {

    // Rezervasyon verisi
    Rezervasyon veri;

    // Sonraki düğümü tutar
    Node sonraki;

    // Constructor
    Node(Rezervasyon veri) {

        this.veri = veri;
        this.sonraki = null;
    }
}

// BeklemeListesi Class

// Kendi bağlı liste yapımız
class BeklemeListesi {

    // Listenin başlangıcı
    Node head;

    // Listeye eleman ekleme
    void ekle(Rezervasyon rezervasyon) {

        // Yeni düğüm oluştur
        Node yeniNode = new Node(rezervasyon);

        // Liste boşsa başa ekle
        if (head == null) {

            head = yeniNode;
            return;
        }

        // Son düğüme kadar git
        Node temp = head;

        while (temp.sonraki != null) {
            temp = temp.sonraki;
        }

        // Sona ekle
        temp.sonraki = yeniNode;
    }

    // Listeyi yazdır
    void yazdir() {

        // Liste boşsa mesaj ver
        if (head == null) {

            System.out.println("Bekleme listesi bos.");
            return;
        }

        Node temp = head;

        while (temp != null) {

            System.out.println(temp.veri);
            temp = temp.sonraki;
        }
    }

    // Liste boş mu kontrol et
    boolean bosMu() {

        return head == null;
    }

    // Uygun rezervasyonu aktif hale getir
    Rezervasyon uygunRezervasyonBul(int odaNumarasi) {

        Node temp = head;
        Node onceki = null;

        while (temp != null) {

            if (temp.veri.oda.odaNumarasi == odaNumarasi) {

                Rezervasyon bulunan = temp.veri;

                // Baştaki eleman silinecekse
                if (onceki == null) {
                    head = temp.sonraki;
                }

                // Aradaki eleman silinecekse
                else {
                    onceki.sonraki = temp.sonraki;
                }

                return bulunan;
            }

            onceki = temp;
            temp = temp.sonraki;
        }

        return null;
    }
}

// Main Class

public class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        HashMap<Integer, Oda> odalar =
                new HashMap<>();

        HashMap<Integer, Musteri> musteriler =
                new HashMap<>();

        ArrayList<Rezervasyon> rezervasyonlar =
                new ArrayList<>();

        // Kendi bağlı liste yapımızı oluşturalım
        BeklemeListesi beklemeListesi =
                new BeklemeListesi();

        // Odaları oluşturalım
        for (int i = 1; i <= 10; i++) {
            odalar.put(i, new Oda(i, "Tek Kisilik"));
        }

        for (int i = 11; i <= 20; i++) {
            odalar.put(i, new Oda(i, "Cift Kisilik"));
        }

        int rezervasyonSayaci = 1;

        while (true) {

            try {

                System.out.println("\n===== OTEL SISTEMI =====");
                System.out.println("1- Musteri Ekle");
                System.out.println("2- Rezervasyon Yap");
                System.out.println("3- Odalari Listele");
                System.out.println("4- Rezervasyonlari Listele");
                System.out.println("5- Bekleme Listesi");
                System.out.println("6- Rezervasyon Iptal Et");
                System.out.println("7- Cikis");

                int secim = scanner.nextInt();

                switch (secim) {

                    case 1:

                        System.out.print("Musteri ID: ");
                        int musteriId = scanner.nextInt();

                        scanner.nextLine();

                        System.out.print("Isim: ");
                        String isim = scanner.nextLine();

                        System.out.print("Telefon: ");
                        String telefon = scanner.nextLine();

                        Musteri musteri =
                                new Musteri(musteriId, isim, telefon);

                        musteriler.put(musteriId, musteri);

                        System.out.println("Musteri eklendi.");
                        break;

                    case 2:

                        System.out.print("Musteri ID: ");
                        int mId = scanner.nextInt();

                        System.out.print("Oda No: ");
                        int odaNo = scanner.nextInt();

                        scanner.nextLine();

                        System.out.print("Giris Tarihi (yyyy-aa-gg): ");
                        String giris = scanner.nextLine();

                        System.out.print("Cikis Tarihi (yyyy-aa-gg): ");
                        String cikis = scanner.nextLine();

                        LocalDate girisTarihi =
                                LocalDate.parse(giris);

                        LocalDate cikisTarihi =
                                LocalDate.parse(cikis);

                        if (!musteriler.containsKey(mId)) {

                            System.out.println(
                                    "Musteri bulunamadi.");

                            break;
                        }

                        if (!odalar.containsKey(odaNo)) {

                            System.out.println(
                                    "Oda bulunamadi.");

                            break;
                        }

                        Musteri bulunanMusteri =
                                musteriler.get(mId);

                        Oda bulunanOda =
                                odalar.get(odaNo);

                        Rezervasyon rezervasyon =
                                new Rezervasyon(
                                        rezervasyonSayaci,
                                        bulunanMusteri,
                                        bulunanOda,
                                        girisTarihi,
                                        cikisTarihi
                                );

                        rezervasyonSayaci++;

                        boolean carpisma = false;

                        for (Rezervasyon r : rezervasyonlar) {

                            if (r.oda.odaNumarasi ==
                                    bulunanOda.odaNumarasi) {

                                boolean uyusmazlik =
                                        cikisTarihi.isBefore(
                                                r.girisTarihi)
                                        || girisTarihi.isAfter(
                                                r.cikisTarihi);

                                if (!uyusmazlik) {

                                    carpisma = true;
                                    break;
                                }
                            }
                        }

                        // Çakışma yoksa rezervasyon oluştur
                        if (!carpisma) {

                            rezervasyonlar.add(rezervasyon);

                            System.out.println(
                                    "Rezervasyon basarili.");
                        }

                        // Çakışma varsa bekleme listesine ekle
                        else {

                            beklemeListesi.ekle(rezervasyon);

                            System.out.println("Oda dolu.");
                            System.out.println(
                                    "Bekleme listesine eklendi.");
                        }

                        break;

                    case 3:

                        for (Oda o : odalar.values()) {

                            System.out.println(o);
                        }

                        break;

                    case 4:

                        if (rezervasyonlar.isEmpty()) {

                            System.out.println(
                                    "Rezervasyon yok.");
                        }

                        else {

                            for (Rezervasyon r : rezervasyonlar) {

                                System.out.println(r);
                            }
                        }

                        break;

                    case 5:

                        beklemeListesi.yazdir();

                        break;

                    case 6:

                        System.out.print("Rezervasyon ID: ");
                        int rId = scanner.nextInt();

                        Rezervasyon silinecek = null;

                        for (Rezervasyon r : rezervasyonlar) {

                            if (r.rezervasyonId == rId) {

                                silinecek = r;
                                break;
                            }
                        }

                        if (silinecek != null) {

                            rezervasyonlar.remove(silinecek);

                            System.out.println(
                                    "Rezervasyon iptal edildi.");

                            Rezervasyon bekleyen =
                                    beklemeListesi
                                            .uygunRezervasyonBul(
                                                    silinecek.oda.odaNumarasi);

                            if (bekleyen != null) {

                                rezervasyonlar.add(bekleyen);

                                System.out.println(
                                        "Beklemedeki rezervasyon aktif edildi.");
                            }
                        }

                        else {

                            System.out.println(
                                    "Rezervasyon bulunamadi.");
                        }

                        break;

                    case 7:

                        System.out.println(
                                "Program kapatildi.");

                        return;

                    default:

                        System.out.println(
                                "Gecersiz secim.");
                }

            }

            // Hata yakalama mekanizması
            catch (Exception e) {

                System.out.println(
                        "Hatali giris yaptiniz.");

                scanner.nextLine();
            }
        }
    }
}
