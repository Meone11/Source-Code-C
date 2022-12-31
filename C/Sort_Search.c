#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PATIENTS 100

typedef struct {
  char nama[100];
  int usia;
  char kelasBpjs[100];
} Pasien;

void inputData(Pasien *pasien, int *n);
void printData(Pasien *pasien, int n);
void sortDataNama(Pasien *pasien, int n);
void sortDataUsia(Pasien *pasien, int n);
void sortDataKelasBpjs(Pasien *pasien, int n);
int searchDataNama(Pasien *pasien, int n, char *keyword);
int minUsia(Pasien *pasien, int n);
int maxUsia(Pasien *pasien, int n);
void Menu();
void SubMenu();

int main() {
  Pasien pasien[MAX_PATIENTS];
  int n, menu, subMenu1, subData, index;
  char keyword[50];
  bool keluar = true;
  bool keluarSubMenu = true;

  do
  {
    Menu();
    printf("Pilihan : "); scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        inputData(pasien, &n);
        printf("\nData Berhasil Di Input!!");
        break;
    case 2:
        do
        {
            SubMenu();
            printf("Pilihan : "); scanf("%d", &subMenu1);

            switch (subMenu1)
            {
            case 1:
                sortDataNama(pasien, n);
                printData(pasien, n);
                break;
            case 2:
                sortDataUsia(pasien, n);
                printData(pasien, n);
                break;
            case 3:
                sortDataKelasBpjs(pasien, n);
                printData(pasien, n);
                break;
            case 4:
                keluarSubMenu = false;
                break;
            
            default:
                break;
            }
        } while (keluarSubMenu);
        
        break;
    case 3:
        getchar();
        printf("Masukan Nama yang Ingin Anda Cari : "); fgets(keyword, 50, stdin);
        printf("Nama yang Ingin Anda Cari : %s", keyword);
        index = searchDataNama(pasien, n, keyword);
        subData = index;
        if (index == -1) {
          printf("Data tidak ditemukan.\n");
        } else {
          printf("Data ditemukan pada Data Ke - %d\n", subData + 1);
          printf("Nama: %s\n", pasien[index].nama);
          printf("Usia: %d\n", pasien[index].usia);
          printf("Kelas BPJS: %s\n", pasien[index].kelasBpjs);
        }
        break;
    case 4:
        printf("Data Maksimum berdasarkan Usia : %d\n", maxUsia(pasien, n));
        printf("Data Minimum berdasarkan Usia : %d\n", minUsia(pasien, n));
        break;
    case 5:
        keluar = false;
        break;
    
    default:
        break;
    }
  } while (keluar);
  

  return 0;
}

void Menu(){
    printf("\n\n============================\n");
    printf("=== Welcome To MyProgram ===\n");
    printf("============================\n");
    printf("          Main Menu         \n");
    printf("1. Input Data\n");
    printf("2. Sorting Data\n");
    printf("3. Searcing Data by Name\n");
    printf("4. Maximum and Minimum\n");
    printf("5. Exit\n");
}

void SubMenu(){
    printf("\n\n============================\n");
    printf("=== Welcome To MyProgram ===\n");
    printf("============================\n");
    printf("          Sub Menu          \n");
    printf("1. By Name\n");
    printf("2. By Age\n");
    printf("3. By BPJS Class\n");
    printf("4. Exit\n");
}

void inputData(Pasien *pasien, int *n) {
  printf("Masukkan jumlah pasien: ");
  scanf("%d", n);
  getchar(); // Abaikan newline setelah input jumlah pasien

  for (int i = 0; i < *n; i++) {
    printf("Masukkan data pasien ke-%d\n", i+1);
    printf("Nama: ");
    fgets(pasien[i].nama, 100, stdin);
    // Hapus newline di akhir string
    pasien[i].nama[strcspn(pasien[i].nama, "\n")] = 0;
    printf("Usia: ");
    scanf("%d", &pasien[i].usia);
    getchar();
    printf("Kelas BPJS: ");
    fgets(pasien[i].kelasBpjs, 100, stdin);
    // Hapus newline di akhir string
    pasien[i].kelasBpjs[strcspn(pasien[i].kelasBpjs, "\n")] = 0;
  }
}


void printData(Pasien *pasien, int n) {
  printf("\nData pasien:\n");
  for (int i = 0; i < n; i++) {
    printf("\nPasien ke-%d\n", i+1);
    printf("Nama: %s\n", pasien[i].nama);
    printf("Usia: %d\n", pasien[i].usia);
    printf("Kelas BPJS: %s\n", pasien[i].kelasBpjs);
  }
}

void sortDataNama(Pasien *pasien, int n) {
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      if (strcmp(pasien[i].nama, pasien[j].nama) > 0) {
        Pasien temp = pasien[i];
        pasien[i] = pasien[j];
        pasien[j] = temp;
      }
    }
  }
}

void sortDataUsia(Pasien *pasien, int n) {
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      if (pasien[i].usia > pasien[j].usia) {
        Pasien temp = pasien[i];
        pasien[i] = pasien[j];
        pasien[j] = temp;
      }
    }
  }
}

void sortDataKelasBpjs(Pasien *pasien, int n) {
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      if (strcmp(pasien[i].kelasBpjs, pasien[j].kelasBpjs) > 0) {
        Pasien temp = pasien[i];
        pasien[i] = pasien[j];
        pasien[j] = temp;
      }
    }
  }
}


int searchDataNama(Pasien *pasien, int n, char *keyword) {
  for (int i = 0; i < n; i++) {
    if (strcmp(pasien[i].nama, keyword) == -10) {
      return i;
    }
  }
  return -1;
}

int minUsia(Pasien *pasien, int n) {
  int min = pasien[0].usia;
  for (int i = 1; i < n; i++) {
    if (pasien[i].usia < min) {
      min = pasien[i].usia;
    }
  }
  return min;
}

int maxUsia(Pasien *pasien, int n) {
  int max = pasien[0].usia;
  for (int i = 1; i < n; i++) {
    if (pasien[i].usia > max) {
      max = pasien[i].usia;
    }
  }
  return max;
}

