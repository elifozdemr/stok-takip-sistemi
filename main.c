#include <stdio.h>

int no;
char isim[35];
int stok;
float fiyat;
struct urun {
    int no;
    char isim[35];
    int stok;
    float fiyat;
};
void urunEkle() {
    FILE* fptr;
    fptr=fopen("urunler.txt","a");
    if(fptr==NULL) {
        printf("Dosya basarisiz\n");
    }
    else {
        printf("Urun bilgilerini giriniz:\t No:\t İsim:\t Stok:\t Fiyat:\n");
        scanf("%d %s %d %f",&no,isim,&stok,&fiyat);
        fprintf(fptr,"%d %s %d %f\n",no,isim,stok,fiyat);
    }
    fclose(fptr);
}
void listele() {
    FILE* fptr;
    fptr=fopen("urunler.txt","r");
    if(fptr==NULL) {
        printf("Dosya basarisiz\n");
    }
    else {
       while ( fscanf(fptr,"%d %s %d %f",&no,isim,&stok,&fiyat)==4){
        printf("%d %s %d %f\n",no,isim,stok,fiyat);
    }
    }
    fclose(fptr);
}
void ara() {
    int arananNO;
     int bulundu=0;
    FILE* fptr;
    fptr=fopen("urunler.txt","r");
    if(fptr==NULL) {
        printf("Dosya basarisiz\n");
    }
    else {
        printf("Aranan mevcut numarayi giriniz: ");
        scanf("%d",&arananNO);
        while (fscanf(fptr,"%d %s %d %f",&no,isim,&stok,&fiyat)==4) {
            if(arananNO==no){
                bulundu=1;
                printf("Aranan numara bulundu\n");
            break;
            }
        }
         if (bulundu==0)
             printf("Aranan numara bulunamadi\n");
        }
    fclose(fptr);
}
void sil() {
    int silNO;
    int bulundu=0;
    FILE* fptr;
    FILE* gecici;
    fptr=fopen("urunler.txt","r");
    gecici=fopen("gecici.txt","w");
    if(fptr==NULL || gecici==NULL) {
        printf("Dosya basarisiz\n");
        if (fptr!=0)
            fclose(fptr);
        if (gecici!=0)
            fclose(gecici);
        return;
    }
    printf("Silinecek mevcut numarayi giriniz: ");
    scanf("%d",&silNO);
    while (fscanf(fptr,"%d %s %d %f",&no,isim,&stok,&fiyat)==4){
        if (no==silNO)
            bulundu=1;
    else
        fprintf(gecici,"%d %s %d %f\n",no,isim,stok,fiyat);
    }
fclose(fptr);
fclose(gecici);
remove("urunler.txt");
    rename("gecici.txt","urunler.txt");
        if (bulundu==1)
            printf("Silinecek urun numarasi bulundu\n");
        if (bulundu==0)
            printf("Silinecek urun numarasi bulunamadi\n");
}
void guncelle() {
    int yeniStok;
    int guncelleNO;
    int bulundu=0;
    FILE* fptr;
    FILE* gecici;
    fptr=fopen("urunler.txt","r");
    gecici=fopen("gecici.txt","w");
    if(fptr==NULL || gecici==NULL) {
        printf("Dosya basarisiz\n");
        if (fptr!=0)
            fclose(fptr);
        if (gecici!=0)
            fclose(gecici);
        return;
    }
        printf("Guncellenecek urunun mevcut numarasini giriniz: ");
        scanf("%d",&guncelleNO);
        printf("Yeni stok miktarini giriniz: ");
        scanf("%d",&yeniStok);
        while (fscanf(fptr,"%d %s %d %f",&no,isim,&stok,&fiyat)==4){
            if (no==guncelleNO){
                bulundu=1;
            fprintf(gecici,"%d %s %d %f\n",no,isim,yeniStok,fiyat);
            }
            else{
                fprintf(gecici,"%d %s %d %f\n",no,isim,stok,fiyat);
}
        }
    fclose(fptr);
    fclose(gecici);
    remove("urunler.txt");
    rename("gecici.txt","urunler.txt");
    if (bulundu==1)
        printf("Stok guncellendi\n");
    if (bulundu==0)
        printf("Stok guncellenemedi\n");
}
void cikis() {
    printf("Cikis yapilmistir.\n");
}
int main() {
    int sec;
    do{
        printf("--------------------------------\n");
        printf("      URUN STOK TAKİP SİSTEMİ   \n");
        printf("--------------------------------\n");
    printf("1-Kullanicidan bilgileri aliniz\n");
    printf("2-Listele\n");
    printf("3-Ara\n");
    printf("4-Sil\n");
    printf("5-Guncelle\n");
    printf("6-Cikis\n");
    printf("1-6 arasinda bir secim yapiniz: \n");
    scanf("%d",&sec);
        switch(sec) {
            case 1:urunEkle();
                break;
                case 2:listele();
                break;
                case 3:ara();
                break;
                case 4:sil();
                break;
                case 5:guncelle();
                break;
                case 6:cikis();
                break;
        }
    }while(sec!=6);
    return 0;
    }