#include <stdio.h>
#include <math.h>

#define MAX 30

typedef struct {
    char name[50];
    int age;
    float usage_time;
} Respondent;

double calculate_mean_int(int arr[], int n) {
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total / n;
}

double calculate_mean_float(float arr[], int n) {
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total / n;
}

double calculate_slope(Respondent respondents[], int n) {
    double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2 = 0.0;
    for (int i = 0; i < n; i++) {
        sum_x += respondents[i].age;
        sum_y += respondents[i].usage_time;
        sum_xy += respondents[i].age * respondents[i].usage_time;
        sum_x2 += pow(respondents[i].age, 2);
    }

    double numerator = (n * sum_xy) - (sum_x * sum_y);
    double denominator = (n * sum_x2) - pow(sum_x, 2);

    return denominator != 0 ? numerator / denominator : 0;
}

double calculate_intercept(Respondent respondents[], int n, double slope) {
    double sum_age = 0.0, sum_usage_time = 0.0;
    for (int i = 0; i < n; i++) {
        sum_age += respondents[i].age;
        sum_usage_time += respondents[i].usage_time;
    }

    double mean_x = sum_age / n;
    double mean_y = sum_usage_time / n;

    return mean_y - (slope * mean_x);
}

void display_table(Respondent respondents[], int n) {
    printf("%-20s%-10s%-15s\n", "Name", "Age", "Usage Time (hrs)");
    printf("%-20s%-10s%-15s\n", "-------------------", "--------", "----------------");
    for (int i = 0; i < n; i++) {
        printf("%-20s%-10d%-15.2f\n", respondents[i].name, respondents[i].age, respondents[i].usage_time);
    }
}

int main() {
    Respondent respondents[MAX] = {
        {"Dina", 13, 4.0}, {"Raka", 14, 3.5}, {"Nina", 15, 5.0},
        {"David", 16, 4.5}, {"Eve", 17, 3.0}, {"Toni", 13, 4.2},
        {"Ica", 14, 3.8}, {"Hannah", 15, 2.5}, {"Melin", 16, 5.0},
        {"Rio", 17, 3.5}, {"Kara", 18, 4.7}, {"Lilik", 19, 3.0},
        {"Dita", 14, 4.0}, {"Nina", 15, 5.0}, {"Dafa", 16, 3.9},
        {"Fira", 18, 3.0}, {"Quinn", 13, 4.5}, {"Rachel", 14, 3.8},
        {"Yuni", 15, 4.0}, {"Tina", 17, 3.7}, {"Uma", 16, 4.2},
        {"Fira", 18, 4.0}, {"Wendy", 19, 3.0}, {"Tito", 16, 3.5},
        {"Gio", 17, 2.9}, {"Zidan", 15, 4.5}, {"Ali", 14, 4.0},
        {"Brian", 13, 3.8}, {"Clara", 15, 4.2}, {"Dylan", 14, 5.0}
    };

    int n = 30;

    printf("\n--- Tabel Data ---\n");
    display_table(respondents, n);

    double slope = calculate_slope(respondents, n);
    double intercept = calculate_intercept(respondents, n, slope);

    printf("\nModel Regresi Linear:\n");
    printf("y = %.2fx + %.2f\n", slope, intercept);

    printf("\nContoh Prediksi:\n");
    int age;
    printf("Masukkan usia untuk prediksi waktu penggunaan: ");
    scanf("%d", &age);
    double predicted_time = slope * age + intercept;
    printf("Prediksi waktu penggunaan untuk usia %d tahun adalah %.2f jam.\n", age, predicted_time);

    return 0;
}
