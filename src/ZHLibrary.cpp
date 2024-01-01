#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


struct Book {
    int id;
    string title;
    string description;
    double rating;
    int numRatings;
    vector<pair<string, int>> responses;  
};


struct User {
    string username;
    string password;
};

void displayBookCollection(const vector<Book>& bukuku) {
    cout << "\nKoleksi Buku:\n";
    for (const Book& book : bukuku) {
        cout << "ID: " << book.id << ", Judul: " << book.title << "\n";
    }
}


void borrowBook(vector<Book>& bukuku) {
    int IdBuku;
    cout << "Masukkan ID buku yang ingin dipinjam: ";
    cin >> IdBuku;

    if (IdBuku >= 1 && IdBuku <= bukuku.size()) {
        cout << "Buku " << bukuku[IdBuku - 1].title << " berhasil dipinjam. Batas waktu peminjaman adalah 2 hari.\n";
       
    } else {
        cout << "ID buku tidak valid.\n";
    }
}


void readOnline(const vector<Book>& bukuku) {
    int IdBuku;
    cout << "Masukkan ID buku yang ingin dibaca online: ";
    cin >> IdBuku;

    if (IdBuku >= 1 && IdBuku <= bukuku.size()) {
        cout << "Anda sedang membaca online: " << bukuku[IdBuku - 1].title << "\n";
    } else {
        cout << "ID buku tidak valid.\n";
    }
}


void ratingBuku(vector<Book>& bukuku) {
    int IdBuku, rating;
    string response;

    cout << "Masukkan ID buku yang ingin diberi tanggapan dan peringkat: ";
    cin >> IdBuku;

    if (IdBuku >= 1 && IdBuku <= bukuku.size()) {
        cout << "Masukkan tanggapan Anda: ";
        cin.ignore();
        getline(cin, response);

        cout << "Masukkan peringkat (1-5): ";
        cin >> rating;

        if (rating >= 1 && rating <= 5) {
            bukuku[IdBuku - 1].responses.push_back({response, rating});

            cout << "Terima kasih atas tanggapan dan peringkat Anda untuk buku " << bukuku[IdBuku - 1].title << ".\n";
        } else {
            cout << "Peringkat tidak valid.\n";
        }
    } else {
        cout << "ID buku tidak valid.\n";
    }
}

void displayResponsesAndRatings(const vector<Book>& bukuku) {
    int IdBuku;
    cout << "Masukkan ID buku yang ingin dilihat tanggapan dan peringkatnya: ";
    cin >> IdBuku;

    if (IdBuku >= 1 && IdBuku <= bukuku.size()) {
        const Book& selectedBook = bukuku[IdBuku - 1];

        cout << "Tanggapan dan Peringkat untuk buku " << selectedBook.title << ":\n";
        for (const auto& response : selectedBook.responses) {
            cout << "Tanggapan: " << response.first << ", Peringkat: " << response.second << "\n";
        }
    } else {
        cout << "ID buku tidak valid.\n";
    }
}


void subscribe() {
    int choice;
    cout << "Pilih berlangganan:\n";
    cout << "[1] Rp69.000 untuk 1 bulan\n";
    cout << "[2] Rp129.000 untuk 4 bulan\n";
    cout << "[3] Rp299.000 untuk 8 bulan\n";
    cout << "Pilih berlangganan (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Anda berlangganan selama 1 bulan.\n";
            break;
        case 2:
            cout << "Anda berlangganan selama 4 bulan.\n";
            break;
        case 3:
            cout << "Anda berlangganan selama 8 bulan.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
    }
}

int main() {
    vector<Book> bookCollection = {
        {1, "Fisiologi", "Fisiologi adalah salah satu cabang ilmu biologi yang mempelajari fungsi dari suatu organisme makhluk hidup dan bagian bagiannya. Objek kajian fisiologi adalah manusia, hewan, dan tumbuhan", 0.0, 0, {}},
        {2, "Filosofi Teras", "Hal yang menarik dari Filosofi Teras ini terletak pada tujuannya yaitu hidup dalam ketenangan dan terbebas dari emosi negatif. Oleh karena itu, pada setiap bab Filososfi Teras terdapat pelajaran yang diambil, salah satunya yaitu dalam menjalani kehidupan harus selaras dengan alam", 0.0, 0, {}},
        {3, "Pschology Of Money", "Buku The Psychology of Money adalah buku yang menjelaskan tentang bagaimana cara seseorang berperilaku terhadap uang. Mulai dari mengelola pikiran, emosi, hingga perilaku ketika sudah dihadapkan dengan uang", 0.0, 0,{}},
        {4, "Dunia Sophie", "adalah sebuah novel filsafat. berkisah tentang seorang gadis berusia 14 tahun yang sebelumnya hidup dengan wajar seperti anak-anak seusianya, hingga suatu ketika ia dikirimi surat misterius berisi pertanyaan-pertanyaan filsafat", 0.0, 0,{}},
        {5,  "HUJAN", "Buku ini menceritakan tentang perjalanan hidup dan kisah cinta seorang wanita yang bernama Lail. Lail dipaksa menjadi yatim piatu sejak usianya masih 13 tahun. Semua bermula saat mendadak terjadi bencana gempa dan gunung meletus yang langsung meluluhlantakkan kota tempatnya tinggal", 0.0, 0,{}},
        {6, "COSMOS carl, sagan", "Buku Kosmos pada dasarnya merupakan buku ilmu pengetahuan, tetapi dengan gaya bahasa yang khas, kita dapat melihat bahwa ilmu pengetahuan dapat menjadi santapan masyarakat luas. Buku ini tidak hanya berguna untuk memperluas cakrawala kita, tetapi juga mengajak kita untuk menghayati dan mencintai penemuan ilmiah", 0.0, 0,{}},
        {7, "Nunchi", "Nunchi adalah suatu bentuk kecerdasan emosional yang dapat dipelajari siapa pun. Yang kita butuhkan hanyalah mata dan telinga untuk memperhatikan orang lain bukan menonjolkan diri sendiri6", 0.0, 0,{}}
    
    };

    vector<User> users;
    User currentUser;

    int loginChoice;
    while (true) {
        cout << "Selamat datang di E-ZHLibrary!\n";
        cout << "[1]. Login\n";
        cout << "[2] Register\n";
        cout << "[0]. Keluar\n";
        cout << "Pilih opsi (0-2): ";
        cin >> loginChoice;

        if (loginChoice == 0) {
            cout << "Terima kasih! Program selesai.\n";
            return 0;
        } else if (loginChoice == 1) {
            string username, password;
            cout << "Masukkan username: ";
            cin >> username;
            cout << "Masukkan password: ";
            cin >> password;

            bool found = false;
            for (const User& user : users) {
                if (user.username == username && user.password == password) {
                    currentUser = user;
                    found = true;
                    break;
                }
            }

            if (found) {
                cout << "Login berhasil. Selamat datang, " << currentUser.username << "!\n";
                break;
            } else {
                cout << "Login gagal. Periksa kembali username dan password Anda.\n";
            }
        } else if (loginChoice == 2) {
            string username, password;
            cout << "Masukkan username: ";
            cin >> username;

            bool exists = false;
            for (const User& user : users) {
                if (user.username == username) {
                    exists = true;
                    break;
                }
            }

            if (exists) {
                cout << "Username sudah terdaftar. Silakan login atau gunakan username lain.\n";
            } else {
                cout << "Masukkan password: ";
                cin >> password;
                users.push_back({username, password});
                cout << "Registrasi berhasil. Silakan login.\n";
            }
        } else {
            cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
        }
    }

    while (true) {
        cout << "\nMenu:\n";
        cout << "[1] Tampilkan Koleksi Buku\n";
        cout << "[2] Peminjaman Buku\n";
        cout << "[3] Baca Online\n";
        cout << "[4] Peringkat dan Ulasan\n";
        cout << "[5] Berlangganan\n";
        cout << "[0] Keluar\n";
        cout << "Pilih menu (0-5): ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                displayBookCollection(bookCollection);
                break;
            case 2:
                borrowBook(bookCollection);
                break;
            case 3:
                readOnline(bookCollection);
                break;
            case 4:
                cout << "\nMenu Peringkat dan Ulasan:\n";
                cout << "1. Berikan Tanggapan dan Peringkat\n";
                cout << "2. Tampilkan Tanggapan\n";
                cout << "Pilih opsi (1-2): ";

                int ratingOption;
                cin >> ratingOption;

                if (ratingOption == 1) {
                    ratingBuku(bookCollection);
                } else if (ratingOption == 2) {
                    displayResponsesAndRatings(bookCollection);
                } else {
                    cout << "Pilihan tidak valid.\n";
                }
                break;
            case 5:
                subscribe();
                break;
            case 0:
                cout << "Terima kasih! Program selesai.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
                break;
        }
    }

    return 0;
}