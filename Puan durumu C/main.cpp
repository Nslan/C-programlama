#include <stdio.h>
void ayar(FILE *,int [],int);
void takimlari_oku(FILE *,char [][13],int ,int );
void sirala_puan(char [],int [],int [],int [],int [],int [],int [],int [],int [],int ,char [][13],int ,int );//takim,puan,averaj,atýlangol,yenilengol,oynananmac,boyut,takýmlarýnisimleri,satýrsayisi,sutunsayisi;
void sirala_averaj(char [],int [],int [],int [],int [],int [],int [],int [],int [],int ,char [][13],int ,int );
int mystrcmp(const char *,const char *);
void ekrana_yazdir(char [],int [],int [],int [],int [],int [],int [],int [],int [],int ,char [][13],int ,int);
void tablo_hesapla(FILE*,int [],int [],int [],int [],int [],int [],int [] ,int ,int ,int  );//evgol,depgol,puan,atýlangol,yenilengol,oynananmac,beraberlik,maglubiye,galibiyet,boyut,y,x,z,macsayisi
void av_hesapla(int [], int[], int [],int); // atýlan gol yenilen gol geri dönen averaj dizisi , boyut
void dosyaya_yaz(FILE*,int [],int [],int [],int [],int [],int [],int [] ,int ,char[][13],int[]);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main() {
	int gal[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int ber[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int mag[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int oynanan[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int puan[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};     
	int ave[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};   
	int at_gol[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};   
	int yen_gol[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char takim[16]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'};   
	char isimler[13][13];
    int ayarlar[4];
	int mac_sayi=0;
	FILE *dosya1=fopen("takimlar.txt","r");
	FILE*dosya3=fopen("ayarlar.txt","r");
	FILE* dosya=fopen("LIG_puan_durumu.txt","w");
	FILE* dosya2=fopen("maclar1.txt","r");

ayar(dosya3,ayarlar,4);//ayarlari dosyadan okuma

takimlari_oku(dosya1,isimler,15,13);//takimlari dosyadan okuma 	
      
tablo_hesapla(dosya2,puan,at_gol,yen_gol,oynanan,ber,mag,gal,ayarlar[1],ayarlar[2],ayarlar[3]);	//dosyadan puan atýlan gol yenilen  gol,oynanan macsayisi,beraberlik,maglubiyeti cekeceðiz ayarlar1=kazandýpuan,ayarlar2=berabere puan,ayarlar3=kaybettipuan

av_hesapla(at_gol,yen_gol,ave,ayarlar[0]);//averaj hesaplama

sirala_puan(takim,puan,ave,at_gol,yen_gol,oynanan,ber,mag,gal,10,isimler,15,13);//ilk önce dizilerimi puan sýralamasýna gore sýralýyorum 

sirala_averaj(takim,puan,ave,at_gol,yen_gol,oynanan,ber,mag,gal,10,isimler,15,13);//ardýndan dizilerimi averaj sýralamasýna gore sýralýyorum

ekrana_yazdir(takim,puan,ave,at_gol,yen_gol,oynanan,ber,mag,gal,10,isimler,ayarlar[0],13);//bu fonksiyon içine aldýðý 

dosyaya_yaz(dosya, puan, at_gol,yen_gol,oynanan, ber, mag, gal,ayarlar[0],isimler,ave);
}


void tablo_hesapla(FILE* dosya2,int puan[],int at_gol[],int yen_gol[],int oynanan[],int ber[],int mag[],int gal[],int x,int y,int z){//maclarý burda okuyup kullanmak ve souc olarak sadece kullanýcagým dizileri burdan almak daha mantýklý
	
	int i=0,mac_sayisi=0;
	char ev[1000][12], dep[1000][12];
	int ev_gol[1000],dep_gol[1000];
	
	while(!feof(dosya2)){
		fscanf(dosya2,"%s %d %s %d",&ev[i],&ev_gol[i],&dep[i],&dep_gol[i]);
		i++;
		mac_sayisi++;
	}
	

	
	for(int i=0; i<mac_sayisi; i++){
	  	for(int j=1; j< mac_sayisi;j++){
		 	if(!mystrcmp(ev[i],ev[i+j]) && !mystrcmp(dep[i],dep[i+j])){
	  		printf("ayni takimlar!!!");
	  		printf("\n%s %s tekrar mac yapamaz!!!! hatayi duzeltince puan durumu hesaplanacaktir",ev[i],dep[i]);
	  	//	return ;
		 }
		  }
	}
	
		for(int i=0; i<mac_sayisi; i++){
	  	
	  	if(ev_gol[i]<0 || dep_gol[i]<0){
	  		printf("\nBIR MAC SONUCU EKSI (-x) DEGER OLAMAZ!!!");
	  		printf("\nMaclar dosyasindaki %d.inci satiri duzeltiniz! hatayi duzeltince puan durumu GUNCELLENECEKTIR!!!",i+1);
	  		//return ;
		 }
	}
		for(int i=0; i<mac_sayisi; i++){
	  	
	  	if(!mystrcmp(ev[i],dep[i])){
	  		printf("\nBIR TAKIM KENDISI ILE mac yapamaz!!!");
	  		printf("\n%s takimi kendisiyle mac yapamaz!!!! hatayi duzeltince puan durumu GUNCELLENECEKTIR!!!",ev[i]);
	  		//return ;
		 }
	}
	
	
	  for(int i=0; i<mac_sayisi; i++){
	  	
	
	  		if(ev_gol[i]==dep_gol[i]){
   
		if(!mystrcmp(ev[i],"A")){                                                        
				puan[0]=puan[0]+y;
				at_gol[0]=at_gol[0]+ev_gol[i];
				yen_gol[0]=yen_gol[0]+dep_gol[i];
				oynanan[0]+=1;
				ber[0]+=1;
            
			}

			else if(!mystrcmp(ev[i],"B")){
				puan[1]=puan[1]+y;
				at_gol[1]=at_gol[1]+ev_gol[i];
				yen_gol[1]=yen_gol[1]+dep_gol[i];
                oynanan[1]+=1;
                ber[1]+=1;
			}
			else if(!mystrcmp(ev[i],"C")){
				puan[2]=puan[2]+y;
				at_gol[2]=at_gol[2]+ev_gol[i];
				yen_gol[2]=yen_gol[2]+dep_gol[i];
				oynanan[2]+=1;
				ber[2]+=1;

			}
			else if(!mystrcmp(ev[i],"D")){
				puan[3]=puan[3]+y;
				at_gol[3]=at_gol[3]+ev_gol[i];
				yen_gol[3]=yen_gol[3]+dep_gol[i];
				oynanan[3]+=1;
				ber[3]+=1;

			}
			else if(!mystrcmp(ev[i],"E")){
				puan[4]=puan[4]+y;
				at_gol[4]=at_gol[4]+ev_gol[i];
				yen_gol[4]=yen_gol[4]+dep_gol[i];
				oynanan[4]+=1;
				ber[4]+=1;

			}
			else if(!mystrcmp(ev[i],"F")){
				puan[5]=puan[5]+y;
				at_gol[5]=at_gol[5]+ev_gol[i];
				yen_gol[5]=yen_gol[5]+dep_gol[i];
				oynanan[5]+=1;
				ber[5]+=1;

			}
			else if(!mystrcmp(ev[i],"G")){
			    puan[6]=puan[6]+y;
				at_gol[6]=at_gol[6]+ev_gol[i];
				yen_gol[6]=yen_gol[6]+dep_gol[i];
				oynanan[6]+=1;
				ber[6]+=1;

			}
			else if(!mystrcmp(ev[i],"H")){
				puan[7]=puan[7]+y;
				at_gol[7]=at_gol[7]+ev_gol[i];
				yen_gol[7]=yen_gol[7]+dep_gol[i];
				oynanan[7]+=1;
				ber[7]+=1;

			}
			else if(!mystrcmp(ev[i],"I")){
				puan[8]=puan[8]+y;
				at_gol[8]=at_gol[8]+ev_gol[i];
				yen_gol[8]=yen_gol[8]+dep_gol[i];
				oynanan[8]+=1;
				ber[8]+=1;

			}
			else if(!mystrcmp(ev[i],"J")){
			    puan[9]=puan[9]+y;
				at_gol[9]=at_gol[9]+ev_gol[i];
				yen_gol[9]=yen_gol[9]+dep_gol[i];
				oynanan[9]+=1;
				ber[9]+=1;

			}
			else if(!mystrcmp(ev[i],"K")){
				puan[10]=puan[10]+y;
				at_gol[10]=at_gol[10]+ev_gol[i];
				yen_gol[10]=yen_gol[10]+dep_gol[i];
				oynanan[10]+=1;
				ber[10]+=1;

			}
			else if(!mystrcmp(ev[i],"L")){
				puan[11]=puan[11]+y;
				at_gol[11]=at_gol[11]+ev_gol[i];
				yen_gol[11]=yen_gol[11]+dep_gol[i];
				oynanan[11]+=1;
				ber[11]+=1;

			}
			else if(!mystrcmp(ev[i],"M")){
			    puan[12]=puan[12]+y;
				at_gol[12]=at_gol[12]+ev_gol[i];
				yen_gol[12]=yen_gol[12]+dep_gol[i];
				oynanan[12]+=1;
				ber[12]+=1;

			}
			else if(!mystrcmp(ev[i],"N")){
				puan[13]=puan[13]+y;
				at_gol[13]=at_gol[13]+ev_gol[i];
				yen_gol[13]=yen_gol[13]+dep_gol[i];
				oynanan[13]+=1;
				ber[13]+=1;

			}
			else if(!mystrcmp(ev[i],"O")){
				puan[14]=puan[14]+y;
				at_gol[14]=at_gol[14]+ev_gol[i];
				yen_gol[14]=yen_gol[14]+dep_gol[i];
				oynanan[14]+=1;
				ber[14]+=1;

			}
			//******************************************************************************
			if(!mystrcmp(dep[i],"A")){
				puan[0]=puan[0]+y;
				at_gol[0]=at_gol[0]+dep_gol[i];
				yen_gol[0]=yen_gol[0]+ev_gol[i];
				oynanan[0]+=1;
				ber[0]+=1;

			}

			else if(!mystrcmp(dep[i],"B")){
				puan[1]=puan[1]+y;
				at_gol[1]=at_gol[1]+dep_gol[i];
				yen_gol[1]=yen_gol[1]+ev_gol[i];
				oynanan[1]+=1;
				ber[1]+=1;

			}
			else if(!mystrcmp(dep[i],"C")){
				puan[2]=puan[2]+y;
				at_gol[2]=at_gol[2]+dep_gol[i];
				yen_gol[2]=yen_gol[2]+ev_gol[i];
				oynanan[2]+=1;
				ber[2]+=1;
			}
			else if(!mystrcmp(dep[i],"D")){
				puan[3]=puan[3]+y;
				at_gol[3]=at_gol[3]+dep_gol[i];
				yen_gol[3]=yen_gol[3]+ev_gol[i];
				oynanan[3]+=1;
				ber[3]+=1;

			}
			else if(!mystrcmp(dep[i],"E")){
				puan[4]=puan[4]+y;
				at_gol[4]=at_gol[4]+dep_gol[i];
				yen_gol[4]=yen_gol[4]+ev_gol[i];
				oynanan[4]+=1;
				ber[4]+=1;

			}
			else if(!mystrcmp(dep[i],"F")){
				puan[5]=puan[5]+y;
				at_gol[5]=at_gol[5]+dep_gol[i];
				yen_gol[5]=yen_gol[5]+ev_gol[i];
				oynanan[5]+=1;
				ber[5]+=1;

			}
			else if(!mystrcmp(dep[i],"G")){
			    puan[6]=puan[6]+y;
				at_gol[6]=at_gol[6]+dep_gol[i];
				yen_gol[6]=yen_gol[6]+ev_gol[i];
				oynanan[6]+=1;
				ber[6]+=1;

			}
			else if(!mystrcmp(dep[i],"H")){
				puan[7]=puan[7]+y;
				at_gol[7]=at_gol[7]+dep_gol[i];
				yen_gol[7]=yen_gol[7]+ev_gol[i];
				oynanan[7]+=1;
				ber[7]+=1;

			}
			else if(!mystrcmp(dep[i],"I")){
				puan[8]=puan[8]+y;
				at_gol[8]=at_gol[8]+dep_gol[i];
				yen_gol[8]=yen_gol[8]+ev_gol[i];
				oynanan[8]+=1;
				ber[8]+=1;

			}
			else if(!mystrcmp(dep[i],"J")){
				puan[9]=puan[9]+y;
				at_gol[9]=at_gol[9]+dep_gol[i];
				yen_gol[9]=yen_gol[9]+ev_gol[i];
				oynanan[9]+=1;
				ber[9]+=1;

			}
			else if(!mystrcmp(dep[i],"K")){
				puan[10]=puan[10]+y;
				at_gol[10]=at_gol[10]+dep_gol[i];
				yen_gol[10]=yen_gol[10]+ev_gol[i];
				oynanan[10]+=1;
				ber[10]+=1;

			}
			else if(!mystrcmp(dep[i],"L")){
				puan[11]=puan[11]+y;
				at_gol[11]=at_gol[11]+dep_gol[i];
				yen_gol[11]=yen_gol[11]+ev_gol[i];
				oynanan[11]+=1;
				ber[11]+=1;

			}
			else if(!mystrcmp(dep[i],"M")){
				puan[12]=puan[12]+y;
				at_gol[12]=at_gol[12]+dep_gol[i];
				yen_gol[12]=yen_gol[12]+ev_gol[i];
				oynanan[12]+=1;
				ber[12]+=1;

			}
			else if(!mystrcmp(dep[i],"N")){
				puan[13]=puan[13]+y;
				at_gol[13]=at_gol[13]+dep_gol[i];
				yen_gol[13]=yen_gol[13]+ev_gol[i];
				oynanan[13]+=1;
				ber[13]+=1;

			}
			else if(!mystrcmp(dep[i],"O")){
			    puan[14]=puan[14]+y;
				at_gol[14]=at_gol[14]+dep_gol[i];
				yen_gol[14]=yen_gol[14]+ev_gol[i];
				oynanan[14]+=1;
				ber[14]+=1;

			}

	     	 }

else if(ev_gol[i]>dep_gol[i]){


			if(!mystrcmp(ev[i],"A")){
				puan[0]=puan[0]+x;
				at_gol[0]=at_gol[0]+ev_gol[i];
				yen_gol[0]=yen_gol[0]+dep_gol[i];
				oynanan[0]+=1;
				gal[0]+=1;

			}

			else if(!mystrcmp(ev[i],"B")){
				puan[1]=puan[1]+x;
				at_gol[1]=at_gol[1]+ev_gol[i];
				yen_gol[1]=yen_gol[1]+dep_gol[i];
				oynanan[1]+=1;
				gal[1]+=1;

			}
			else if(!mystrcmp(ev[i],"C")){
				puan[2]=puan[2]+x;
				at_gol[2]=at_gol[2]+ev_gol[i];
				yen_gol[2]=yen_gol[2]+dep_gol[i];
				oynanan[2]+=1;
				gal[2]+=1;

			}
			else if(!mystrcmp(ev[i],"D")){
				puan[3]=puan[3]+x;
				at_gol[3]=at_gol[3]+ev_gol[i];
				yen_gol[3]=yen_gol[3]+dep_gol[i];
				oynanan[3]+=1;
				gal[3]+=1;
			}
			else if(!mystrcmp(ev[i],"E")){
				puan[4]=puan[4]+x;
				at_gol[4]=at_gol[4]+ev_gol[i];
				yen_gol[4]=yen_gol[4]+dep_gol[i];
				oynanan[4]+=1;
				gal[4]+=1;

			}
			else if(!mystrcmp(ev[i],"F")){
				puan[5]=puan[5]+x;
				at_gol[5]=at_gol[5]+ev_gol[i];
				yen_gol[5]=yen_gol[5]+dep_gol[i];
				oynanan[5]+=1;
				gal[5]+=1;

			}
			else if(!mystrcmp(ev[i],"G")){
				puan[6]=puan[6]+x;
				at_gol[6]=at_gol[6]+ev_gol[i];
				yen_gol[6]=yen_gol[6]+dep_gol[i];
				oynanan[6]+=1;
				gal[6]+=1;

			}
			else if(!mystrcmp(ev[i],"H")){
			    puan[7]=puan[7]+x;
				at_gol[7]=at_gol[7]+ev_gol[i];
				yen_gol[7]=yen_gol[7]+dep_gol[i];
				oynanan[7]+=1;
				gal[7]+=1;

			}
			
			    else if(!mystrcmp(ev[i],"I")){
				puan[8]=puan[8]+x;
				at_gol[8]=at_gol[8]+ev_gol[i];
				yen_gol[8]=yen_gol[8]+dep_gol[i];
				oynanan[8]+=1;
				gal[8]+=1;

			}
				else if(!mystrcmp(ev[i],"J")){
				puan[9]=puan[9]+x;
				at_gol[9]=at_gol[9]+ev_gol[i];
				yen_gol[9]=yen_gol[9]+dep_gol[i];
				oynanan[9]+=1;
				gal[9]+=1;

			}	else if(!mystrcmp(ev[i],"K")){
				puan[10]=puan[10]+x;
				at_gol[10]=at_gol[10]+ev_gol[i];
				yen_gol[10]=yen_gol[10]+dep_gol[i];
				oynanan[10]+=1;
				gal[10]+=1;

			}	else if(!mystrcmp(ev[i],"L")){
				puan[11]=puan[11]+x;
				at_gol[11]=at_gol[11]+ev_gol[i];
				yen_gol[11]=yen_gol[11]+dep_gol[i];
				oynanan[11]+=1;
				gal[11]+=1;

			}	else if(!mystrcmp(ev[i],"M")){
				puan[12]=puan[12]+x;
				at_gol[12]=at_gol[12]+ev_gol[i];
				yen_gol[12]=yen_gol[12]+dep_gol[i];
				oynanan[12]+=1;
				gal[12]+=1;

			}	else if(!mystrcmp(ev[i],"N")){
				puan[13]=puan[13]+x;
				at_gol[13]=at_gol[13]+ev_gol[i];
				yen_gol[13]=yen_gol[13]+dep_gol[i];
				oynanan[13]+=1;
				gal[13]+=1;

			}	else if(!mystrcmp(ev[i],"O")){
				puan[14]=puan[14]+x;
				at_gol[14]=at_gol[14]+ev_gol[i];
				yen_gol[14]=yen_gol[14]+dep_gol[i];
				oynanan[14]+=1;
				gal[14]+=1;
	
			}//**************
		
		   	if(!mystrcmp(dep[i],"A")){
				puan[0]=puan[0]+z;
				at_gol[0]=at_gol[0]+dep_gol[i];
				yen_gol[0]=yen_gol[0]+ev_gol[i];
				oynanan[0]+=1;
				mag[0]+=1;

			}

			else if(!mystrcmp(dep[i],"B")){
				puan[1]=puan[1]+z;
				at_gol[1]=at_gol[1]+dep_gol[i];
				yen_gol[1]=yen_gol[1]+ev_gol[i];
				oynanan[1]+=1;
				mag[1]+=1;
               

			}
			else if(!mystrcmp(dep[i],"C")){
				puan[2]=puan[2]+z;
				at_gol[2]=at_gol[2]+dep_gol[i];
				yen_gol[2]=yen_gol[2]+ev_gol[i];
				oynanan[2]+=1;
				mag[2]+=1;

			}
			else if(!mystrcmp(dep[i],"D")){
				puan[3]=puan[3]+z;
				at_gol[3]=at_gol[3]+dep_gol[i];
				yen_gol[3]=yen_gol[3]+ev_gol[i];
				oynanan[3]+=1;
				mag[3]+=1;

			}
			else if(!mystrcmp(dep[i],"E")){
				puan[4]=puan[4]+z;
				at_gol[4]=at_gol[4]+dep_gol[i];
				yen_gol[4]=yen_gol[4]+ev_gol[i];
				oynanan[4]+=1;
				mag[4]+=1;

			}
			else if(!mystrcmp(dep[i],"F")){
				puan[5]=puan[5]+z;
				at_gol[5]=at_gol[5]+dep_gol[i];
				yen_gol[5]=yen_gol[5]+ev_gol[i];
				oynanan[5]+=1;
				mag[5]+=1;

			}
			else if(!mystrcmp(dep[i],"G")){
				puan[6]=puan[6]+z;
				at_gol[6]=at_gol[6]+dep_gol[i];
				yen_gol[6]=yen_gol[6]+ev_gol[i];
				oynanan[6]+=1;
				mag[6]+=1;

			}
			else if(!mystrcmp(dep[i],"H")){
				puan[7]=puan[7]+z;
				at_gol[7]=at_gol[7]+dep_gol[i];
				yen_gol[7]=yen_gol[7]+ev_gol[i];
				oynanan[7]+=1;
				mag[7]+=1;

			}
			else if(!mystrcmp(dep[i],"I")){
				puan[8]=puan[8]+z;
				at_gol[8]=at_gol[8]+dep_gol[i];
				yen_gol[8]=yen_gol[8]+ev_gol[i];
				oynanan[8]+=1;
				mag[8]+=1;

			}
			else if(!mystrcmp(dep[i],"J")){
				puan[9]=puan[9]+z;
				at_gol[9]=at_gol[9]+dep_gol[i];
				yen_gol[9]=yen_gol[9]+ev_gol[i];
				oynanan[9]+=1;
				mag[9]+=1;
			}
			else if(!mystrcmp(dep[i],"K")){
				puan[10]=puan[10]+z;
				at_gol[10]=at_gol[10]+dep_gol[i];
				yen_gol[10]=yen_gol[10]+ev_gol[i];
				oynanan[10]+=1;
				mag[10]+=1;

			}
			else if(!mystrcmp(dep[i],"L")){
				puan[11]=puan[11]+z;
				at_gol[11]=at_gol[11]+dep_gol[i];
				yen_gol[11]=yen_gol[11]+ev_gol[i];
				oynanan[11]+=1;
				mag[11]+=1;
			}
			else if(!mystrcmp(dep[i],"M")){
				puan[12]=puan[12]+z;
				at_gol[12]=at_gol[12]+dep_gol[i];
				yen_gol[12]=yen_gol[12]+ev_gol[i];
				oynanan[12]+=1;
				mag[12]+=1;

			}
			else if(!mystrcmp(dep[i],"N")){
				puan[13]=puan[13]+z;
				at_gol[13]=at_gol[13]+dep_gol[i];
				yen_gol[13]=yen_gol[13]+ev_gol[i];
				oynanan[13]+=1;
				mag[13]+=1;

			}
			else if(!mystrcmp(dep[i],"O")){
				puan[14]=puan[14]+z;
				at_gol[14]=at_gol[14]+dep_gol[i];
				yen_gol[14]=yen_gol[14]+ev_gol[i];
				oynanan[14]+=1;
				mag[14]+=1;

			}
			
				

	       	}
else if(ev_gol[i]<dep_gol[i]){//****************************************************************************************************************************************************************************************

			if(!mystrcmp(ev[i],"A")){
				puan[0]=puan[0]+z;
				at_gol[0]=at_gol[0]+ev_gol[i];
				yen_gol[0]=yen_gol[0]+dep_gol[i];
				oynanan[0]+=1;
				mag[0]+=1;

			}

			else if(!mystrcmp(ev[i],"B")){
				puan[1]=puan[1]+z;
				at_gol[1]=at_gol[1]+ev_gol[i];
				yen_gol[1]=yen_gol[1]+dep_gol[i];
				oynanan[1]+=1;
				mag[1]+=1;


			}
			else if(!mystrcmp(ev[i],"C")){
				puan[2]=puan[2]+z;
				at_gol[2]=at_gol[2]+ev_gol[i];
				yen_gol[2]=yen_gol[2]+dep_gol[i];
				oynanan[2]+=1;
				mag[2]+=1;

			}
			else if(!mystrcmp(ev[i],"D")){
				puan[3]=puan[3]+z;
				at_gol[3]=at_gol[3]+ev_gol[i];
				yen_gol[3]=yen_gol[3]+dep_gol[i];
				oynanan[3]+=1;
				mag[3]+=1;

			}
			else if(!mystrcmp(ev[i],"E")){
				puan[4]=puan[4]+z;
				at_gol[4]=at_gol[4]+ev_gol[i];
				yen_gol[4]=yen_gol[4]+dep_gol[i];
				oynanan[4]+=1;
				mag[4]+=1;

			}
			else if(!mystrcmp(ev[i],"F")){
				puan[5]=puan[5]+z;
				at_gol[5]=at_gol[5]+ev_gol[i];
				yen_gol[5]=yen_gol[5]+dep_gol[i];
				oynanan[5]+=1;
				mag[5]+=1;

			}
			else if(!mystrcmp(ev[i],"G")){
				puan[6]=puan[6]+z;
				at_gol[6]=at_gol[6]+ev_gol[i];
				yen_gol[6]=yen_gol[6]+dep_gol[i];
				oynanan[6]+=1;
				mag[6]+=1;

			}
			else if(!mystrcmp(ev[i],"H")){
				puan[7]=puan[7]+z;
				at_gol[7]=at_gol[7]+ev_gol[i];
				yen_gol[7]=yen_gol[7]+dep_gol[i];
				oynanan[7]+=1;
				mag[7]+=1;

			}
			
		   else if(!mystrcmp(ev[i],"I")){
				puan[8]=puan[8]+z;
				at_gol[8]=at_gol[8]+ev_gol[i];
				yen_gol[8]=yen_gol[8]+dep_gol[i];
				oynanan[8]+=1;
				mag[8]+=1;

			}	
			else if(!mystrcmp(ev[i],"J")){
				puan[9]=puan[9]+z;
				at_gol[9]=at_gol[9]+ev_gol[i];
				yen_gol[9]=yen_gol[9]+dep_gol[i];
				oynanan[9]+=1;
				mag[9]+=1;

			}
				else if(!mystrcmp(ev[i],"K")){
				puan[10]=puan[10]+z;
				at_gol[10]=at_gol[10]+ev_gol[i];
				yen_gol[10]=yen_gol[10]+dep_gol[i];
				oynanan[10]+=1;
				mag[10]+=1;

			}
				else if(!mystrcmp(ev[i],"L")){
				puan[11]=puan[11]+z;
				at_gol[11]=at_gol[11]+ev_gol[i];
				yen_gol[11]=yen_gol[11]+dep_gol[i];
				oynanan[11]+=1;
				mag[11]+=1;

			}
				else if(!mystrcmp(ev[i],"M")){
				puan[12]=puan[12]+z;
				at_gol[12]=at_gol[12]+ev_gol[i];
				yen_gol[12]=yen_gol[12]+dep_gol[i];
				oynanan[12]+=1;
				mag[12]+=1;

			}
				else if(!mystrcmp(ev[i],"N")){
				puan[13]=puan[13]+z;
				at_gol[13]=at_gol[13]+ev_gol[i];
				yen_gol[13]=yen_gol[13]+dep_gol[i];
				oynanan[13]+=1;
				mag[13]+=1;

			}
				else if(!mystrcmp(ev[i],"O")){
				puan[14]=puan[14]+z;
				at_gol[14]=at_gol[14]+ev_gol[i];
				yen_gol[14]=yen_gol[14]+dep_gol[i];
				oynanan[14]+=1;
				mag[14]+=1;

			}

			//******************************************************************************
			if(!mystrcmp(dep[i],"A")){
				puan[0]=puan[0]+x;
				at_gol[0]=at_gol[0]+dep_gol[i];
				yen_gol[0]=yen_gol[0]+ev_gol[i];
				oynanan[0]+=1;
				gal[0]+=1;


			}

			else if(!mystrcmp(dep[i],"B")){
				puan[1]=puan[1]+x;
				at_gol[1]=at_gol[1]+dep_gol[i];
				yen_gol[1]=yen_gol[1]+ev_gol[i];
				oynanan[1]+=1;
				gal[1]+=1;


			}
			else if(!mystrcmp(dep[i],"C")){
				puan[2]=puan[2]+x;
				at_gol[2]=at_gol[2]+dep_gol[i];
				yen_gol[2]=yen_gol[2]+ev_gol[i];
				oynanan[2]+=1;
				gal[2]+=1;


			}
			else if(!mystrcmp(dep[i],"D")){
				puan[3]=puan[3]+x;
				at_gol[3]=at_gol[3]+dep_gol[i];
				yen_gol[3]=yen_gol[3]+ev_gol[i];
				oynanan[3]+=1;
				gal[3]+=1;


			}
			else if(!mystrcmp(dep[i],"E")){
				puan[4]=puan[4]+x;
				at_gol[4]=at_gol[4]+dep_gol[i];
				yen_gol[4]=yen_gol[4]+ev_gol[i];
				oynanan[4]+=1;
				gal[4]+=1;


			}
			else if(!mystrcmp(dep[i],"F")){
				puan[5]=puan[5]+x;
				at_gol[5]=at_gol[5]+dep_gol[i];
				yen_gol[5]=yen_gol[5]+ev_gol[i];
				oynanan[5]+=1;
				gal[5]+=1;


			}
			else if(!mystrcmp(dep[i],"G")){
				puan[6]=puan[6]+x;
				at_gol[6]=at_gol[6]+dep_gol[i];
				yen_gol[6]=yen_gol[6]+ev_gol[i];
				oynanan[6]+=1;
				gal[6]+=1;


			}
			else if(!mystrcmp(dep[i],"H")){
				puan[7]=puan[7]+x;
				at_gol[7]=at_gol[7]+dep_gol[i];
				yen_gol[7]=yen_gol[7]+ev_gol[i];
				oynanan[7]+=1;
				gal[7]+=1;


			}
			
			else if(!mystrcmp(dep[i],"I")){
				puan[8]=puan[8]+x;
				at_gol[8]=at_gol[8]+dep_gol[i];
				yen_gol[8]=yen_gol[8]+ev_gol[i];
				oynanan[8]+=1;
				gal[8]+=1;


			}
			else if(!mystrcmp(dep[i],"J")){
				puan[9]=puan[9]+x;
				at_gol[9]=at_gol[9]+dep_gol[i];
				yen_gol[9]=yen_gol[9]+ev_gol[i];
				oynanan[9]+=1;
				gal[9]+=1;


			}
			else if(!mystrcmp(dep[i],"K")){
				puan[10]=puan[10]+x;
				at_gol[10]=at_gol[10]+dep_gol[i];
				yen_gol[10]=yen_gol[10]+ev_gol[i];
				oynanan[10]+=1;
				gal[10]+=1;


			}
			else if(!mystrcmp(dep[i],"L")){
				puan[11]=puan[11]+x;
				at_gol[11]=at_gol[11]+dep_gol[i];
				yen_gol[11]=yen_gol[11]+ev_gol[i];
				oynanan[11]+=1;
				gal[11]+=1;


			}
			else if(!mystrcmp(dep[i],"M")){
				puan[12]=puan[12]+x;
				at_gol[12]=at_gol[12]+dep_gol[i];
				yen_gol[12]=yen_gol[12]+ev_gol[i];
				oynanan[12]+=1;
				gal[12]+=1;


			}
			else if(!mystrcmp(dep[i],"N")){
				puan[13]=puan[13]+x;
				at_gol[13]=at_gol[13]+dep_gol[i];
				yen_gol[13]=yen_gol[13]+ev_gol[i];
				oynanan[13]+=1;
				gal[13]+=1;


			}
			else if(!mystrcmp(dep[i],"O")){
				puan[14]=puan[14]+x;
				at_gol[14]=at_gol[14]+dep_gol[i];
				yen_gol[14]=yen_gol[14]+ev_gol[i];
				oynanan[14]+=1;
				gal[14]+=1;

			}
      }	  		
       }
	}

void sirala_puan(char takim[],int dizi[],int dizi1[],int dizi3[],int dizi4[],int dizi5[],int ber[],int mag[],int gal[],int boyut,char isimler [][13],int satirsayisi,int sutunsayisi){
	int i,k,j,temp,temp1;
  	for( i=0; i < boyut-1; i++ ) {
		// Ikinci dongu, her asamada yapilan
		// islemi temsil eder. Dizinin elemanlari
		// en sondan baslayarak kontrol edilir.
		// Eger kendisinden once gelen elemandan
		// kucuk bir degeri varsa, elemanlarin
		// degerleri yer degistirir.
		for( j = boyut-1; j > i; j-- )  {               // dizi boyut-1 synyr alynyr
			if( dizi[ j ] > dizi[ j - 1 ] ) {

				temp = dizi[ j -1 ];
				dizi[ j - 1 ] = dizi[ j ];
				dizi[ j ] = temp;
				
				temp1=takim[j-1];
				takim[j-1]=takim[j];
				takim[j]=temp1;
     		    
     		    temp=dizi1[j-1];
				dizi1[j-1]=dizi1[j];
				dizi1[j]=temp;

				  temp1=dizi3[j-1];
				  dizi3[j-1]=dizi3[j];
				  dizi3[j]=temp1;

				   temp1=dizi4[j-1];
		           dizi4[j-1]=dizi4[j];
			       dizi4[j]=temp1;
			       
			         temp1=dizi5[j-1];
		           dizi5[j-1]=dizi5[j];
			       dizi5[j]=temp1;
			       
			       temp1=ber[j-1];
		           ber[j-1]=ber[j];
			       ber[j]=temp1;
			       
			       temp1=mag[j-1];
		           mag[j-1]=mag[j];
			       mag[j]=temp1;
			       
			       temp1=gal[j-1];
		           gal[j-1]=gal[j];
			       gal[j]=temp1;
			       
			    for( k = 0; k < 13; k++ ){
				   
			       
			       temp1=isimler[j-1][k];
		           isimler[j-1][k]=isimler[j][k];
		           isimler[j][k]=temp1;
                   }
				
			 
	    	 }
	   }  	
     }   
	 		
}


void sirala_averaj(char takim[],int dizi[],int dizi1[],int dizi3[],int dizi4[],int dizi5[],int ber[],int mag[],int gal[],int boyut,char isimler [][13],int satirsayisi,int sutunsayisi){
	int i,j,k,temp,temp1;
  	for( i=0; i < boyut-1; i++ ) {
		// Ikinci dongu, her asamada yapilan
		// islemi temsil eder. Dizinin elemanlari
		// en sondan baslayarak kontrol edilir.
		// Eger kendisinden once gelen elemandan
		// kucuk bir degeri varsa, elemanlarin
		// degerleri yer degistirir.
		for( j = boyut-1; j > i; j-- )  {               // dizi boyut-1 synyr alynyr
		if(dizi[i]==dizi[j]){


			               	if(dizi1[i]<dizi1[j]){

				          temp = dizi[ j -1 ];
				dizi[ j - 1 ] = dizi[ j ];
				dizi[ j ] = temp;
				
				temp1=takim[j-1];
				takim[j-1]=takim[j];
				takim[j]=temp1;
     		    
     		    temp=dizi1[j-1];
				dizi1[j-1]=dizi1[j];
				dizi1[j]=temp;

				  temp1=dizi3[j-1];
				  dizi3[j-1]=dizi3[j];
				  dizi3[j]=temp1;

				   temp1=dizi4[j-1];
		           dizi4[j-1]=dizi4[j];
			       dizi4[j]=temp1;
			          temp1=dizi5[j-1];
		           dizi5[j-1]=dizi5[j];
			       dizi5[j]=temp1;
			       
			       temp1=ber[j-1];
		           ber[j-1]=ber[j];
			       ber[j]=temp1;
			       
			       temp1=mag[j-1];
		           mag[j-1]=mag[j];
			       mag[j]=temp1;
			       
			       temp1=gal[j-1];
		           gal[j-1]=gal[j];
			       gal[j]=temp1;
			       
			       for( k = 0; k < 13; k++ ){
				   
			       
			       temp1=isimler[j-1][k];
		           isimler[j-1][k]=isimler[j][k];
		           isimler[j][k]=temp1;
                   }
					 
	    	 }
	   }  	
     }   	 		
   }
}

void ayar(FILE *d,int bosdizi[],int boyut){//gonderilen dosyayý oku ve beraberinde gonderilen bosdiziye bu okudugun verileri yerleþtir
	for(int i=0;!feof(d);i++){
		fscanf(d,"%d",&bosdizi[i]);
	}	
}

int mystrcmp(const char *s1, const char *s2)
{
            int retValue = 0;
            //yazylardaki karakterler e?it oldu?u sürece döner.
            while( *s1 == *s2 )
            {
                        if(*s1 == '\0')
                        {
                                    // '\0' karakterine gelmesi ikisinin e?it olmasy
                                    retValue = 0;
                                    break;
                        }
                        ++s1;
                        ++s2;
            }
            // karakterler farkly olunca döngüden çykar.
            // iki karakterin farky ile geri döner.
            retValue = *s1 - *s2;

            return retValue;
}

void av_hesapla(int atilan_gol [], int yenilen_gol[], int averaj[],int boyut){
	
	int i=0;
	         for(i=0; i<boyut; i++){
	         	
	         	
	         	averaj[i]=atilan_gol[i]-yenilen_gol[i];
	  	
	         	
			 }
}

void ekrana_yazdir(char takim[],int dizi[],int dizi1[],int dizi3[],int dizi4[],int dizi5[],int ber[],int mag[],int gal[],int boyut,char isimler [][13],int satir,int sutun){
	int i;
		printf("\n\n");
		printf("TKM\tPUAN\tAVE\tAG\tYG\tOMS\tBER\tMAG\tGAL\n");
	for(i=0; i<boyut; i++){		
            printf("%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\n",takim[i],dizi[i],dizi1[i],dizi3[i],dizi4[i],dizi5[i],ber[i],mag[i],gal[i],isimler[i]);
	}

	
}

void takimlari_oku(FILE *dosya1,char isimler[][13],int satir,int sutun){
		 int k=0;
		 while(!feof(dosya1)){
		 fscanf(dosya1,"%s\n",&isimler[k]);
     	 k++;
		 }	
}

void dosyaya_yaz(FILE* tablo,int puan[],int at_gol[],int yen_gol[],int oynanan[],int ber[],int mag[],int gal[],int takim_say,char isimler[][13],int ave[]){
	
	int i=0;
	fprintf(tablo,"Puan\tAVE\tAG\tYG\tOMS\tBER\tMAG\tGAL\tTAKIM\n");
	for( i=0; i < takim_say; i++ ){
	fprintf(tablo,"\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t",puan[i],ave[i],at_gol[i],yen_gol[i],oynanan[i],ber[i],mag[i],gal[i],isimler[i]);
	
	}
		
}

