#include <stdio.h>

int main() {
    // Inisialisasi variabel
    int login_attempt =0 ;
    float balance = 50000000.0;
    int pin =150523 ;
    
    // Menu login
    printf("=== Selamat datang di ATM ===\n");
    while (login_attempt < 3) {
        int input_pin;
        printf("Masukkan PIN Anda: ");
        scanf("%d", &input_pin);
        if (input_pin == pin) {
            printf("Login berhasil.\n");
            // Menu utama
            int choice = 0;
            while (choice != 7) {
                printf("\n=== Menu Utama ===\n");
                printf("1. Lihat saldo\n");
                printf("2. Isi saldo\n");
                printf("3. Penarikan\n");
                printf("4. Transfer\n");
                printf("5. Top up\n");
                printf("6. Log out\n");
                printf("Pilihan Anda: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        // Cek saldo
                        printf("Saldo Anda: Rp %.2f\n", balance);
                        break;
                    case 2:
                        // Isi saldo
                        float deposit;
                        printf("Masukkan jumlah uang yang ingin diisi: Rp ");
                        scanf("%f", &deposit);
                        if (deposit <= 0) {
                            printf("Jumlah yang dimasukkan tidak valid.\n");
                        } else {
                            balance += deposit;
                            printf("Isi saldo berhasil. Saldo Anda sekarang: Rp %.2f\n", balance);
                        }
                        break;
                    case 3:
                        // Penarikan
                        float withdraw;
                        printf("Masukkan jumlah uang yang ingin ditarik: Rp ");
                        scanf("%f", &withdraw);
                        if (withdraw > balance) {
                            printf("Saldo tidak mencukupi.\n");
                        } else if (withdraw <= 0) {
                            printf("Jumlah yang dimasukkan tidak valid.\n");
                        } else {
                            balance -= withdraw;
                            printf("Penarikan berhasil. Saldo Anda sekarang: Rp %.2f\n", balance);
                        }
                        break;
                    case 4:
                        // Transfer
                        float transfer_amount;
                        int transfer_account;
                        printf("Masukkan nomor rekening tujuan: ");
                        scanf("%d", &transfer_account);
                        printf("Masukkan jumlah uang yang ingin ditransfer: Rp ");
                        scanf("%f", &transfer_amount);
                        if (transfer_amount > balance) {
                            printf("Saldo tidak mencukupi.\n");
                        } else if (transfer_amount <= 0) {
                            printf("Jumlah yang dimasukkan tidak valid.\n");
                        } else {
                            balance -= transfer_amount;
                            printf("Transfer berhasil. Saldo Anda sekarang: Rp %.2f\n", balance);
                        }
                        break;
                    case 5:
                        // Top up
                        int top_up_choice;
                        printf("Pilih jenis top up: \n");
                        printf("1. Dana\n");
                        printf("2. Gopay\n");
                        printf("3. PLN\n");
                        printf("4. ShoppePay\n");
                        printf("5. Telkomsel\n");
                        printf("Pilihan Anda: ");
                        scanf("%d", &top_up_choice);
                        switch (top_up_choice) {
                            case 1:
                                // Top up dana
                                float top_up_dana;
                                printf("Masukkan jumlah uang yang ingin diisi: Rp ");
                            scanf("%f", &top_up_dana);
                            if (top_up_dana <= 0) {
                                printf("Jumlah yang dimasukkan tidak valid.\n");
                            } else {
                                balance -= top_up_dana;
                                printf("Top up Dana berhasil. Saldo Anda sekarang: Rp %.2f\n", balance);
                            }
                            break;
                        case 2:
                            // Top up gopay
                            float top_up_gopay;
                            printf("Masukkan jumlah uang yang ingin anda isi: Rp ");
                            scanf("%f", &top_up_gopay);
                            if (top_up_gopay <= 0) {
                                printf("Jumlah yang dimasukkan tidak valid.\n");
                            } else {
                                balance -= top_up_gopay;
                                printf("Top up Gopay berhasil. Saldo Anda sekarang: Rp %.2f\n", balance);
                            }
                            break;
                              case 3:
                                // PLN
                                float top_up_pln;
                                printf("Masukkan jumlah pulsa pln yang ingin diisi: Rp ");
                            scanf("%f", &top_up_pln);
                            if (top_up_pln <= 0) {
                                printf("Jumlah yang dimasukkan tidak valid.\n");
                            } else {
                                balance -= top_up_pln;
                                printf("Top up Pln berhasil. Saldo Anda sekarang: Rp %.2f\n", balance);
                            }
                            break;
                              case 4:
                                // Top up ShoppePay
                                float top_up_ShoppePay;
                                printf("Masukkan jumlah uang yang ingin diisi: Rp ");
                            scanf("%f", &top_up_ShoppePay);
                            if (top_up_ShoppePay <= 0) {
                                printf("Jumlah yang dimasukkan tidak valid.\n");
                            } else {
                                balance -= top_up_ShoppePay;
                                printf("Top up ShoppePay berhasil. Saldo Anda sekarang: Rp %.2f\n", balance);
                            }
                            break;
                              case 5:
                                // isi pulsa Telkomsel
                                float isi_pulsa_telkomsel;
                                printf("Masukkan jumlah pulsa yang ingin diisi: Rp ");
                            scanf("%f", &isi_pulsa_telkomsel);
                            if (isi_pulsa_telkomsel <= 0) {
                                printf("Jumlah yang dimasukkan tidak valid.\n");
                            } else {
                                balance -= isi_pulsa_telkomsel;
                                printf("Isi Pulsa Telkomse berhasil. Saldo Anda sekarang: Rp %.2f\n", balance);
                            }
                            break;
                        default:
                            printf("Pilihan tidak valid.\n");
                    }
                    break;
                case 6:
                    // Log out
                    printf("Terima kasih telah menggunakan ATM.\n");
                    login_attempt = 3;
                    break;
                default:
                    printf("Pilihan tidak valid.\n");
            }
        }
    } else {
        printf("PIN salah. Silakan coba lagi.\n");
        login_attempt++;
    }
}
if (login_attempt == 3) {
    printf("Anda telah memasukkan PIN yang salah sebanyak tiga kali. Kartu ATM Anda terblokir.\n");
}
return 0;
}