#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
	int NO;
	char Nama[30];
	int Nilai;
} siswa;

void menu(siswa Data[]);
void tampil(siswa Data[]);

int ascDesc, sortBy;
int pilihan, n;

int main(){
	siswa Data[MAX], Data2[MAX];
	
	printf("%-25s", "Panjang Array"); printf(": ");
	scanf("%d", &n);
	fflush(stdin);
	
	alokasi(Data2);
	
	do {
		copyData(Data2, Data);
		printf("%-25s", "Data array awal"); printf(": ");
		tampil(Data);
		menu(Data);
		printf("%-25s", "Data array terurut"); printf(": ");
		tampil(Data);
	} while(pilihan != 5);
}

int copyData(siswa Data2[], siswa Data[]){
	int i;
	
	for(i=0; i<n; i++){
		Data[i].NO = Data2[i].NO;
		strcpy(Data[i].Nama, Data2[i].Nama);
		Data[i].Nilai = Data2[i].Nilai;
	}
}

int alokasi(siswa Data2[]){
	int i;
	
	for(i=0; i<n; i++){
		printf("Data Array ke %d \n", i+1);
		printf("%-10s", "NO"); printf(": ");
		scanf("%d", &Data2[i].NO);
		fflush(stdin);
		printf("%-10s", "Nama"); printf(": ");
		scanf("%s", &Data2[i].Nama);
		fflush(stdin);
		printf("%-10s", "Nilai"); printf(": ");
		scanf("%d", &Data2[i].Nilai);
		fflush(stdin);
	}
}

void menu(siswa Data[]){
	printf("========================\n");
	printf(" MENU METODE SORTING\n");
	printf("========================\n");
	printf("1. Insertion Sort\n");
	printf("2. Selection Sort\n");
	printf("3. Bubble Sort\n");
	printf("4. Shell Sort\n");
	printf("5. Keluar\n");
	printf("%-25s", "Pilih Menu"); printf(": ");
	scanf("%d", &pilihan);
	fflush(stdin);
	
	if(pilihan == 5)
		exit(0);
		
	modeUrut();
	urutDari();
		
	switch(pilihan){
		case 1:
			insertion(Data);
			break;
		case 2:
			selection(Data);
			break;
		case 3:
			bubble(Data);
			break;
		case 4:
			shell(Data);
			break;
	}
}

int modeUrut(){
	printf("========================\n");
	printf(" MENU MODE SORTING\n");
	printf("========================\n");
	printf("1. Ascending\n");
	printf("2. Descending\n");
	printf("%-25s", "Pilih Menu"); printf(": ");
	scanf("%d", &ascDesc);
	fflush(stdin);
	
}

int urutDari(){
	printf("========================\n");
	printf(" MENU SORTING BY\n");
	printf("========================\n");
	printf("1. NO\n");
	printf("2. Nama\n");
	printf("3. Nilai\n");
	printf("%-25s", "Pilih Menu"); printf(": ");
	scanf("%d", &sortBy);
	fflush(stdin);
	
}

int insertion(siswa Data[]){
	
	int i, j, kondisi = 0;
	siswa key;
	
	for(i=1; i<n; i++){
		key = Data[i];
		j = i - 1;
		while(j >= 0){
			if(ascDesc == 1){
				if(sortBy == 1)
					kondisi = Data[j].NO > key.NO;
				else if(sortBy == 2)
					kondisi = strcmpi(Data[j].Nama, key.Nama) > 0;
				else if(sortBy == 3)
					kondisi = Data[j].Nilai > key.Nilai;
			} else {
				if(sortBy == 1)
					kondisi = Data[j].NO < key.NO;
				else if(sortBy == 2)
					kondisi = strcmpi(Data[j].Nama, key.Nama) < 0;
				else if(sortBy == 3)
					kondisi = Data[j].Nilai < key.Nilai;
			}
				
			if(kondisi){
				Data[j+1] = Data[j];
				j = j - 1;
			} else {
				break;	
			}
		}
		Data[j+1] = key;
	}
}

int selection(siswa Data[]){
	
	int i,j, x, kondisi = 0;
    for(i=0; i<n-1; i++){
        x = i;
    
        for(j = i+1; j<n; j++){
        	if(ascDesc == 1){
        		if(sortBy == 1)
        			kondisi = Data[j].NO < Data[x].NO;
        		else if(sortBy == 2)
        			kondisi = strcmpi(Data[j].Nama, Data[x].Nama) < 0;
        		else if(sortBy == 3)
        			kondisi = Data[j].Nilai < Data[x].Nilai;
			} else {
				if(sortBy == 1)
        			kondisi = Data[j].NO > Data[x].NO;
        		else if(sortBy == 2)
        			kondisi = strcmpi(Data[j].Nama, Data[x].Nama) > 0;
        		else if(sortBy == 3)
        			kondisi = Data[j].Nilai > Data[x].Nilai;
			} 

        	if(kondisi){
        		x = j;
			}
		}
        tukar(&Data[i], &Data[x]);
    }
	
}

int bubble(siswa Data[]){
	
	int i, j, kondisi = 0, flag = 1, akhir = n-2;

	for(i=0; i<=n-2; i++){
		flag = 0;
		for(j=0; j<=akhir; j++){
			if(ascDesc == 1){
				if(sortBy == 1)
					kondisi = Data[j].NO > Data[j+1].NO;
				else if(sortBy == 2)
					kondisi = strcmpi(Data[j].Nama, Data[j+1].Nama) > 0;
				else if(sortBy == 3)
					kondisi = Data[j].Nilai > Data[j+1].Nilai;
			} else {
				if(sortBy == 1)
					kondisi = Data[j].NO < Data[j+1].NO;
				else if(sortBy == 2)
					kondisi = strcmpi(Data[j].Nama, Data[j+1].Nama) < 0;
				else if(sortBy == 3)
					kondisi = Data[j].Nilai < Data[j+1].Nilai;
			}
				
			if(kondisi){
				tukar(&Data[j], &Data[j+1]);
				flag = 1;
			}
		}
		if(flag == 0)
			break;
		akhir--; 
	}
}

int shell(siswa Data[]){
	
	int i, j, jarak,  kondisi = 0, flag;
	
	for(jarak=n/2; jarak>=1; jarak=jarak/2){
		flag = 1;
		while(flag == 1){
			flag = 0; 
			for(i=0; i<n-jarak; i++){
				if(ascDesc == 1){
					if(sortBy == 1)
						kondisi = Data[i].NO > Data[i+jarak].NO;
					else if(sortBy == 2)
						kondisi = strcmpi(Data[i].Nama, Data[i+jarak].Nama) > 0;
					else if(sortBy == 3)
						kondisi = Data[i].Nilai > Data[i+jarak].Nilai;
					
				} else {
					if(sortBy == 1)
						kondisi = Data[i].NO < Data[i+jarak].NO;
					else if(sortBy == 2)
						kondisi = strcmpi(Data[i].Nama, Data[i+jarak].Nama) < 0;
					else if(sortBy == 3)
						kondisi = Data[i].Nilai < Data[i+jarak].Nilai;
				}
				
				if(kondisi){
					tukar(&Data[i], &Data[i+jarak]);
					flag = 1;
				}
			}
		}
	}
}

int tukar(siswa *a, siswa *b){
	siswa temp;
	
    temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(siswa Data[]){
	int i;
	printf("\n");
	printf("%-5s", "NO"); printf("%-15s", "Nama"); printf("%-10s", "Nilai");
	for(i=0; i<n; i++){
		printf("\n");
		printf("%-5d ", Data[i].NO); printf("%-15s ", Data[i].Nama); printf("%-10d ", Data[i].Nilai);
	}
	printf("\n\n");
}
