#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_OPTIONS 15

typedef struct {
  char* word;
  char* synonyms[MAX_NUM_OPTIONS];
} WordWithSynonyms;

int main(int argc, char* argv[]) {
  // Pastikan file.txt dapat dibuka
  FILE* input_file = fopen("ADJ.txt", "r");
  if (input_file == NULL) {
    printf("Gagal membuka file.txt\n");
    return 1;
  }

  // Baca file.txt baris per baris
  char line[MAX_LINE_LENGTH];
  WordWithSynonyms words_with_synonyms[MAX_LINE_LENGTH];
  int num_words = 0;

  while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {

    // Pemisah antara kata dan sinonim adalah ":", maka cari posisi ":" dalam baris
    char* colon_pos = strchr(line, ':');
    if (colon_pos != NULL) {

      // Temukan posisi "," setelah ":"
      char* comma_pos = strchr(colon_pos + 1, ',');
      while (comma_pos != NULL) {

        // Ambil kata dan sinonim dari baris
        *colon_pos = '\0';  // Tandai akhir dari kata dengan NULL character
        words_with_synonyms[num_words].word = strdup(line);  // Salin kata ke struct
        *comma_pos = '\0';  // Tandai akhir dari sinonim dengan NULL character
        words_with_synonyms[num_words].synonyms[0] = strdup(colon_pos + 1);  // Salin sinonim pertama ke struct
        int num_synonyms = 1;

        // Cari sinonim lainnya yang dipisahkan ","
        char* next_comma_pos = strchr(comma_pos + 1, ',');
        while (next_comma_pos != NULL) {
          *next_comma_pos = '\0';  // Tandai akhir dari sinonim dengan NULL character
          words_with_synonyms[num_words].synonyms[num_synonyms] = strdup(comma_pos + 1);  // Salin sinonim ke struct
          num_synonyms++;
          comma_pos = next_comma_pos;
          next_comma_pos = strchr(comma_pos + 1, ',');
        }

        if (num_synonyms < MAX_NUM_OPTIONS) {
          // Salin sinonim terakhir ke struct
          words_with_synonyms[num_words].synonyms[num_synonyms] = strdup(comma_pos + 1);
          num_synonyms++;
        }

        // Tandai bahwa tidak ada sinonim lain dengan menetapkan NULL pada elemen sinonim berikutnya
        words_with_synonyms[num_words].synonyms[num_synonyms] = NULL;
        num_words++;
      }
    }
  }

  // Tutup file.txt
  fclose(input_file);

  // Buka file output.txt untuk ditulis
  FILE* output_file = fopen("Soal_Ujian.txt", "w");
  if (output_file == NULL) {
    printf("Gagal membuka output.txt\n");
    return 1;
  }

  // Susun soal ujian
  int num_questions = 0;
  for (int i = 0; i < num_words; i++) {
    // Cetak soal pilihan ganda ke file output.txt
    if (num_questions < 10) {
      fprintf(output_file, "Soal %d (pilihan ganda):\n", num_questions + 1);
      fprintf(output_file, "%s berarti:\n", words_with_synonyms[i].word);
      // Acak urutan sinonim
      int num_synonyms = 0;
      while (words_with_synonyms[i].synonyms[num_synonyms] != NULL) {
        num_synonyms++;
      }
      for (int j = num_synonyms - 1; j > 0; j--) {
        int k = rand() % (j + 1);
        char* temp = words_with_synonyms[i].synonyms[j];
        words_with_synonyms[i].synonyms[j] = words_with_synonyms[i].synonyms[k];
        words_with_synonyms[i].synonyms[k] = temp;
      }
      // Cetak sinonim ke file output.txt
      char option = 'A';
      for (int j = 0; j < num_synonyms; j++) {
        fprintf(output_file, "%c. %s\n", option, words_with_synonyms[i].synonyms[j]);
        option++;
      }
      num_questions++;
    }
    // Cetak soal essay ke file output.txt
    if (num_questions < 15) {
      fprintf(output_file, "Soal %d (essay):\n", num_questions + 1);
      fprintf(output_file, "Berikan sinonim dari kata %s:\n", words_with_synonyms[i].word);
      num_questions++;
    }
  }

  // Tutup file output.txt
  fclose(output_file);

  return 0;
}
