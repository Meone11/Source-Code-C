#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32
#define Soal_choice 10
#define ESSAY 5

int main(int argc, char *argv[])
{
    FILE *input = fopen("ADJ.txt", "r");
    if (input == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output = fopen("exam.txt", "w");
    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    // Array yang menyimpan kata dan sinonimnya
    char words[MAX_LINE_LENGTH][MAX_WORD_LENGTH];
    int num_words = 0;

    // Baca file input dan masukkan kata dan sinonimnya ke dalam array
    char line[MAX_LINE_LENGTH];
   
    while (fgets(line, MAX_LINE_LENGTH, input) != NULL) {
        char *p = strtok(line, ":");
        if (p != NULL) {
            strcpy(words[num_words++], p);
        }
        p = strtok(NULL, ",\n");
        while ( p != NULL) {
            strcpy(words[num_words++], p);
            p = strtok(NULL, ",\n");
        }
    }

    // Acak urutan array
    srand(time(NULL));
    for (int i = 0; i < num_words; i++) {
        int j = rand() % num_words;
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
    }

    // Buat soal ujian
    int correct_answer[Soal_choice] = {};
    int indek_choice = 0;
    int indeks_soal = 0;
    for (int i = 0; i < num_words; i += 5) {
        if (i == ((5*Soal_choice) + (5*ESSAY))){
            break;
        }else if (i < (5*Soal_choice)){

            // Cetak pertanyaan
            fprintf(output, "\n%d.( ) %s?\n", indeks_soal + 1, words[i]);

            // Acak urutan pilihan jawaban
            srand(time(NULL));
            int choice_order[5] = {0, 1, 2, 3, 4};
            for (int j = 0; j < 5; j++) {
            
                int k = rand() % 5;
                int temp = choice_order[j];
                choice_order[j] = choice_order[k];
                choice_order[k] = temp;
            }

            // Cetak pilihan jawaban (4 pilihan)
            fprintf(output, "(1) %s\n", words[i + choice_order[0] + 1]);
            fprintf(output, "(2) %s\n", words[i + choice_order[1] + 1]);
            fprintf(output, "(3) %s\n", words[i + choice_order[2] + 1]);
            fprintf(output, "(4) %s\n", words[i + choice_order[3] + 1]);
            fprintf(output, "(5) %s\n", words[i + choice_order[4] + 1]);

            // Cari jawaban yang benar
            for (int j = 0; j < 5; j++) {
                if (strcmp(words[i + choice_order[j] + 1], words[i]) >= 0) {
                    correct_answer[indek_choice++] = j + 1;
                    break;
                }else{
                    correct_answer[indek_choice++] = j + 2;
                    break;
                }
            }

            indeks_soal++;

        }else if (i >= 50 && i < 75){
             // Cetak pertanyaan
            fprintf(output, "\n%d.( ) %s?\n",indeks_soal + 1, words[i]);

            // Acak urutan pilihan jawaban
            srand(time(NULL));
            int choice_order[5] = {0, 1, 2, 3, 4};
            for (int j = 0; j < 5; j++) {
            
                int k = rand() % 5;
                int temp = choice_order[j];
                choice_order[j] = choice_order[k];
                choice_order[k] = temp;
            }
            indeks_soal++;
        }
        
    }

    for (int i = 0; i < Soal_choice; i++){
        fprintf(output, "%d, ", correct_answer[i]);
    }
    // fprintf(output, "\n");

    printf("File Berhasil Di Buat!!!");

    fclose(input);
    fclose(output);

    return 0;
}
