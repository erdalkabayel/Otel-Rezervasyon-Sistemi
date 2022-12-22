//
//  main.c
//  rezervasyon sistemi
//
//  Created by Erdal Kabayel on 19.12.2022.
/*
 Mac kullandığım için programı Xcode'da yazdım. Fakat Mac'de conio.h ve windows.h kütüphanesi bulunmadığı için program çalışmadı. Sanal makineye Windows kurup orada yazdım. Dev C++, Codeblocks ve Visual Studio'da setlocale kullanmama rağmen Türkçe karakter bastıramadım. Sanal makinede dil paketi olmamasından kaynaklı olabilir diye düşünüp karakterlerin ASCII kodlarını tanıtmayı denedim fakat hata aldım. Sonunda sistemin düzgün gözükmesi için tüm Türkçe karakterleri çıkardım.
 
 
 */
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void kayit();
void liste();
void duzenle();
void sil();
void ara();
void giris()
{

	int a=0,i=0;
    char kullanici1[10],c=' ';
    char parola1[10],code[10];
    char kullanici2[10]="admin";
    char parola2[10]="admin";
    do
{
	system("cls");

    setlocale(LC_ALL, "Turkish");
    printf("\n  --------------------------  GAZI OTEL REZERVASYON SISTEMI  --------------------------  ");
    printf(" \n                       KULLANICI ADINIZI GIRIN:-");
	scanf("%s", &kullanici1);
	printf(" \n                       PAROLANIZI GIRIN:-");
	while(i<10)
	{
	    parola1[i]=getch();
	    c=parola1[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	parola1[i]='\0';

	i=0;

		if(strcmp(kullanici1,kullanici2)==0 && strcmp(parola1,parola2)==0)
	{
	printf("  \n\n\n       GIRIS BASARILI. HOS GELDINIZ.");

	break;
	}
	else
	{
		printf("\n        GIRIS BASARISIZ. KULLANICI ADI VEYA PAROLA HATALI.");
		a++;

		getch();

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nGIRIS YAPILAMIYOR. KULLANICI ADINI VE PAROLAYI 3 KEZ YANLIS GIRDINIZ!");

		getch();

		}
		system("cls");
}

struct musteribilgi
{
	char oda_no[10];
	char ad_soyad[20];
	char yas[10];
	char telefon[15];
	char email[20];
	char sure[10];
	char baslangic[10];
}s;

int main(){
	int i=0;
    setlocale(LC_ALL, "Turkish");
	time_t t;
	time(&t);
	char musteriadi;
	char secim;
    giris();
    system("cls");
	while (1)
	{
		system("cls");
		 for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("   ------------------------------  |ANA MENU|  ----------------------------- \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("\t\t 'Lütfen Klavyeden Seçimizi Yapınız:");
		printf("\n\n");
		printf(" \n 1'e BAS  -> Musteri Kaydi Yap");
		printf("\n------------------------");
		printf(" \n 2'ye BAS -> Musteri Kaydi Kontrol Et");
		printf("\n----------------------------------");
		printf(" \n 3'e BAS  -> Musteri Kaydi Sil");
		printf("\n-----------------------------------");
		printf(" \n 4'e BAS  -> Musteri Kaydi Ara");
		printf("\n-----------------------------------");
		printf(" \n 5'e BAS  -> Musteri Kaydi Duzenle");
		printf("\n-----------------------");
		printf(" \n 6'ya BAS -> Sistemden Cik");
		printf("\n-----------------");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nTarih : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");

		secim=getche();
		secim=toupper(secim);
		switch(secim)
		{
			case '1':
				kayit();break;
			case '2':
				liste();break;
			case '3':
				sil();break;
			case '4':
				ara();break;
			case '5':
				duzenle();break;
			case '6':
				system("cls");
				printf("\n\n\t -----TESEKKURLER-----");
				exit(0);
				break;
			default:
				system("cls");
				printf("Hatali Giris");
				printf("\n Devam Etmek Icin Herhangi Bir Tusa Bas.");
				getch();
		}
	}
}

void kayit()
{
    FILE *f;
	char test;
	f=fopen("kayit.txt","a+");
	if(f==0)
	{   f=fopen("kayit.txt","w+");
		system("cls");
		printf("Islem Gerceklesirken Lutfen Bekleyin");
		printf("\n Islem Tamamlandi. Devam Etmek Icin Herhangi Bir Tusa Basin");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Musteri Bilgilerini Giriniz:");
		printf("\n Oda Numarasini Giriniz:");
		scanf("\n %s",s.oda_no);
		fflush(stdin);
		printf("Ad-Soyad Giriniz(Bosluk Yerine '.' Kullaniniz):");
		scanf("\n %s",s.ad_soyad);
		printf("\nYas Giriniz:");
		scanf("\n %s",s.yas);
		printf("\nTelefon Numarasi Giriniz:");
		scanf("\n %s",s.telefon);
		printf("\nE-Posta Giriniz:");
		scanf("\n %s",s.email);
		printf("\nKalinacak Sureyi Giriniz(\'x\'gun):");
		scanf("\n %s",&s.sure);
		printf("\nBaslangic Gunu Giriniz(gg\\aa\\yyyy):");
		scanf("\n %s",&s.baslangic);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\n1 Oda Basariyla Rezerve Edildi");
		printf("\n Cıkmak Icin 'ESC'ye Basiniz, Baska Bir Kayit Yapmak icin Herhangi Bir Tusa Basiniz:");
		test=getche();
		if(test==27)
			break;

	}
	fclose(f);
}
void liste()
{
	FILE *f;
	int i;
	if((f=fopen("kayit.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf("ODA   ");
	printf("\tAD-SOYAD");
	printf("\t\tYAS ");
	printf("\tTELEFON ");
	printf("\tE-POSTA ");
	printf("\t\t KALINACAK SURE ");
	printf("\t BASLANGIC \n");

	for(i=0;i<118;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{

		printf("\n%s\t%s \t\t%s \t%s \t%s \t\t%s \t\t%s",s.oda_no,s.ad_soyad,s.yas,s.telefon,s.email,s.sure,s.baslangic);
	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	getch();
}

void sil()
{
	FILE *f,*t;
	int i=1;
	char oda_no[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("kayit.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("Kayitlardan Silinecek Olan Oda Numarasini Giriniz \n");
	fflush(stdin);
	scanf("%s",oda_no);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.oda_no,oda_no)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{
		printf("\n\n Boyle Bir Oda Kaydi Bulunamadi");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("kayit.txt");
	rename("temp.txt","kayit.txt");
	printf("\n\nKayit Basariyla Silindi.");
	fclose(f);
	fclose(t);
	getch();
}

void ara()
{
system("cls");
	FILE *f;
	char oda_no[20];
	int flag=1;
	f=fopen("kayit.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Kayit Bilgilerini Aramak Icin Oda Numarasini Girin: \n");
	scanf("%s", oda_no);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.oda_no,oda_no)==0){
			flag=0;
			printf("\n\tKayit Bulundu\n ");
			printf("\nOda Numarasi:\t%s",s.oda_no);
			printf("\nAd-Soyad:\t%s",s.ad_soyad);
			printf("\nYas:\t%s",s.yas);
			printf("\nTelefon:\t%s",s.telefon);
			printf("\nE-Posta:\t%s",s.email);
			printf("\nKalinacak Sure:\t%s",s.sure);
			printf("\nBaslangic:\t%s",s.baslangic);
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("\n\tAramis Oldugunuz Kayit Bulunamadi!");
	}
	getch();
	fclose(f);
}

void duzenle()
{
	FILE *f;
	int k=1;
	char oda_no[20];
	long int size=sizeof(s);
	if((f=fopen("kayit.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("Duzenlemek Istediginiz Kaydin Oda Numarasini Giriniz :\n\n");
	scanf("%[^\n]",oda_no);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.oda_no,oda_no)==0)
		{
			k=0;
			printf("\nOda Numarasi Girin     :");
			gets(s.oda_no);
			printf("\nAd-Soyad Girin    :");
			fflush(stdin);
			scanf("%s",&s.ad_soyad);
			printf("\nYas Girin       :");
			scanf("%s",&s.yas);
			printf("\nTelefon Numarasi Girin :");
			scanf("%f",&s.telefon);
			printf("\nE-Posta Girin :");
			scanf("%s",&s.email);
			printf("\nKalinacak Sure Girin :");
			scanf("%s",&s.sure);
			printf("\nBaslangic Girin :");
			scanf("%s",&s.baslangic);
			fseek(f,size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	if(k==1){
		printf("\n\nBOYLE BIR KAYIT YOK!");
		fclose(f);
		getch();
	}else{
	fclose(f);
	printf("\n\n\t\tKayit Basariyla Duzenlendi!");
	getch();
}
}
