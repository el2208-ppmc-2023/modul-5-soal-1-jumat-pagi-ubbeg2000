/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <math.h>

#define TS 0.01 // Time sampling untuk hitung percepatan

float motor(float input, int count)
{
    if (count == 0)
    {
        return 0.0;
    }

    else
    {
        // Karna input step, maka x(n-1) = x(n)
        return (0.00413 * input + 0.00413 * input + 0.992 * motor(input, count - 1));
    }

    /******************************************************
     * Untuk Validasi tanpa rekursif (silakan uncomment)
     ******************************************************/

    // x[0] = input;
    // y[0] = 0.0;
    // for (int i = 1; i <= count; i++)
    // {
    //     x[i] = input;
    //     y[i] = (0.00413 * x[i] + 0.00413 * x[i - 1] + 0.992 * y[i - 1]);
    // }
    // return y[count];
}

/* sampling time = 100ms */

int main()
{
    float inputSig;
    int total;

    printf("Masukkan sinyal input: ");
    scanf("%f", &inputSig);

    printf("Masukkan jumlah titik penelitian: ");
    scanf("%d", &total);

    int node[total];
    float accel[total], vel[total];

    for (int i = 0; i < total; i++)
    {
        printf("Seleksi node ke-%d: ", i + 1);
        scanf("%d", &node[i]);
    }

    printf("\nHasil Simulasi:\n");
    for (int i = 0; i < total; i++)
    {
        vel[i] = motor(inputSig, node[i]);
        accel[i] = (vel[i] - motor(inputSig, node[i] - 1)) / TS;
        int roundedVel = roundf(vel[i]);
        int roundedAccel = roundf(accel[i]);
        printf("Saat n=%d; v=%d m/s; a=%d m/s2\n", node[i], roundedVel, roundedAccel);
    }

    return 0;
}
