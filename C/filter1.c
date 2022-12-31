#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32

typedef struct {
    char word[MAX_WORD_LENGTH];
    char synonyms[4][MAX_WORD_LENGTH];
    int num_synonyms;
    int correct_synonym;
} Word;

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    // Baca file input dan masukkan ke dalam array words
    Word words[MAX_LINE_LENGTH];
    int num_words = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input) != NULL) {
        // Parsing kata dan sinonim
        char *word = strtok(line, ":");
        char *synonym_str = strtok(NULL, ":");
        char *synonym = strtok(synonym_str, ",");
        int i = 0;
        while (synonym != NULL) {
            strcpy(words[num_words].synonyms[i], synonym);
            i++;
            synonym = strtok(NULL, ",");
        }
        words[num_words].num_synonyms = i;
        strcpy(words[num_words].word, word);

        // Tentukan sinonim yang benar
        if (i == 1) {
            words[num_words].correct_synonym = 0;
        } else {
            words[num_words].correct_synonym = -1;
        }
        num_words++;
    }
    
    // Acak urutan array words
    srand(time(NULL));
    for (int i = 0; i < num_words; i++) {
        int j = rand() % num_words;
        Word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }

    // Buat soal pilihan ganda
    for (int i = 0; i < num_words; i++) {
        // Cetak pertanyaan
        fprintf(output, "Apa sinonim dari kata '%s'?\n", words[i].word);
        
        // Acak urutan pilihan jawaban
        int choice_order[4] = {0, 1, 2, 3};
        for (int j = 0; j < 4; j++) {
            int k = rand() % 4;
            int temp = choice_order[j];
            choice_order[j] = choice_order[k];
            choice_order[k] = temp;
        }

        fprintf(output, "A. %s\n", words[i].synonyms[choice_order[0]]);
        fprintf(output, "B. %s\n", words[i].synonyms[choice_order[1]]);
        fprintf(output, "C. %s\n", words[i].synonyms[choice_order[2]]);
        fprintf(output, "D. %s\n", words[i].synonyms[choice_order[3]]);

        // Cari sinonim yang belum pernah digunakan sebelumnya
        int num_unused_synonyms = 0;
        char unused_synonyms[4][MAX_WORD_LENGTH];
        for (int j = 0; j < words[i].num_synonyms; j++) {
            int flag = 0;
            for (int k = 0; k < i; k++) {
                if (strcmp(words[k].synonyms[j], words[i].synonyms[j]) == 0) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                strcpy(unused_synonyms[num_unused_synonyms], words[i].synonyms[j]);
                num_unused_synonyms++;
            }
        }

        // Cetak pilihan jawaban (4 pilihan)
        // if (num_unused_synonyms >= 0) {
        //     // Jika ada sinonim yang belum pernah digunakan sebelumnya, gunakan sebagai jawaban
        //     fprintf(output, "A. %s\n", words[i].synonyms[choice_order[0]]);
        //     fprintf(output, "B. %s\n", words[i].synonyms[choice_order[1]]);
        //     fprintf(output, "C. %s\n", words[i].synonyms[choice_order[2]]);
        //     fprintf(output, "D. %s\n", words[i].synonyms[choice_order[3]]);
        // } 
        // else {
        //     // Jika tidak ada sinonim yang belum pernah digunakan sebelumnya, gunakan sinonim dari kata lain yang belum pernah digunakan sebagai jawaban
        //     int j = 0;
        //     for (int k = 0; k < i; k++) {
        //         if (k == i) continue;

        //         for (int l = 0; l < words[k].num_synonyms; l++) {
        //             int flag = 0;
        //             for (int m = 0; m < i; m++) {
        //                 if (strcmp(words[m].synonyms[l], words[k].synonyms[l]) == 0) {
        //                     flag = 1;
        //                     break;
        //                 }
        //             }
        //             if (!flag) {
        //                 strcpy(unused_synonyms[j], words[k].synonyms[l]);
        //                 j++;
        //             }
        //         }
        //     }

        //     fprintf(output, "A. %s\n", words[i].synonyms[choice_order[0]]);
        //     fprintf(output, "B. %s\n", words[i].synonyms[choice_order[1]]);
        //     fprintf(output, "C. %s\n", words[i].synonyms[choice_order[2]]);
        //     fprintf(output, "D. %s\n", words[i].synonyms[choice_order[3]]);
        // }

        // Tentukan jawaban yang benar
        if (words[i].correct_synonym == -1) {
            // Jika tidak ada sinonim yang benar, jawaban yang benar adalah sinonim yang belum pernah digunakan sebelumnya
            int correct_answer = -1;
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < num_unused_synonyms; k++) {
                    if (strcmp(unused_synonyms[k], words[i].synonyms[choice_order[j]]) == 0) {
                        correct_answer = j;
                        break;
                    }
                }
                if (correct_answer != -1) break;
            }
            fprintf(output, "Jawaban: %c\n\n", 'A' + correct_answer);
        } else {
            // Jika ada sinonim yang benar, jawaban yang benar adalah sinonim yang benar
            int correct_answer = 0;
            for (int j = 0; j < 4; j++) {
                if (choice_order[j] == words[i].correct_synonym) {
                    correct_answer = j;
                    break;
                }
            }
            fprintf(output, "Jawaban: %c\n\n", 'A' + correct_answer);
        }
    }

    fclose(input);
    fclose(output);

    return 0;
}


