#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <cctype>
using namespace std;
#define MAX 16

int arr[MAX];
int leftTop = -1;    // Stack trai
int rightTop = MAX;  // Stack phai

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Danh sach de thao tac
void Menu(int pos) {
    string menu[5] = {"1. Push Trai", "2. Push Phai", "3. Pop Trai", "4. Pop Phai", "5. Thoat"};
    for (int i = 0; i < 5; i++) {
        if (i == pos) {
            setColor(240); // Nen trang chu den de cho thay o dag chon 
            cout << ">   " << menu[i] << "     (Nhan Enter de chon)\n";
            setColor(7);   // Tra lai nen den mac dinh  
        } else {
            cout << "  " << menu[i] << "\n";
        }
    }
    cout << "\n\n";
} 

// Ve bang demo stack 2 dau
void Demostack() {
    cout << "\n\n\n             ";
    for (int i = -1 ; i <= MAX; i++) {
        if (i == leftTop) cout << "  St1  ";
        else if (i == rightTop) cout << "St2";
        else cout << "     ";
    }
    cout << "\n";
    cout << "                   ";
    for (int i = 0; i < MAX; i++) {
        cout << "[";
        if(i<8){
        	cout << setw(2) << i+1 << " ";
		} 
		else{
			cout << setw(2) << 8*2-i << " ";
		}
        cout << "]";
    }
    cout << "\n                   ";
    cout << "_______________________________________||_______________________________________\n                   ";
    for (int i = 0; i < MAX; i++) {
        cout << "|" << "   " << "|";
	}
	cout << "\n                   ";
    for (int i = 0; i < MAX; i++) {
        cout << "|";
        if (i <= leftTop || i >= rightTop) {
            cout << setw(3) << arr[i];
        } else {
            cout << "   ";
        }
        cout << "|";
    }
    cout << "\n                   ";
    for (int i = 0; i < MAX; i++) {
        cout << "|" << "___" << "|";
	}
    cout << "\n               ";
    for (int i = -1; i <= MAX; i++) {
        if (i == leftTop) cout << " ^  ";
        else if (i == rightTop) cout << "  ^";
        else cout << "     ";
    }
        cout << "\n               ";
    for (int i = -1; i <= MAX; i++) {
        if (i == leftTop) cout << " ^  ";
        else if (i == rightTop) cout << "  ^";
        else cout << "     ";
    }
    cout << "\n";
}

void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hien thong bao khi stack day
void Hien_Tb(string Tb) {
    gotoXY(50, 25);
    cout << Tb;
    Sleep(2000); // Dung man hinh 2s de hien thong bao
}

bool IsNotNumber(string s) {
    if (s.empty()){
    	Hien_Tb("Vui long nhap so!");
    	return true;
	}
    for (char c : s) {
        if (!isdigit(c)){
        	Hien_Tb("Vui long nhap so!");
        	return true;
		}
    }
    return false;
}

// thao tác them ben trai
void pushLeft(string val) {
	if(IsNotNumber(val)){
		cin.clear();
    	cin.ignore(1000, '\n');
		return;
	}
	int x=stoi(val);
    if (leftTop + 1 == rightTop) {
        Hien_Tb("Stack day!\n"); 
		return;
    }
    arr[++leftTop] = x;
}

// Thao tac them ben phai
void pushRight(string val) {
	if(IsNotNumber(val)){
		cin.clear();
    	cin.ignore(1000, '\n');
		return;
	}
	int x=stoi(val);
    if (rightTop - 1 == leftTop) {
        Hien_Tb("Stack day!\n"); 
		return;
    }
    arr[--rightTop] = x;
}

// Thao tac xoa ben trai
void popLeft() {
    if (leftTop == -1) return;
    leftTop--;
}

// Thao tac xoa ben phai
void popRight() {
    if (rightTop == MAX) return;
    rightTop++;
}

int main() {
    int x = 0;
    int n = 1;
    while (n) {
        system("cls");// Xoa man hinh cu
        Menu(x);// In menu
        Demostack();// In bang demo stack 2 dau
        int key = _getch();// Nhap dau mui ten
        if (key == 224) {
            key = _getch();
            if (key == 72) x = (x-1+5)%5; // Len
            else if (key == 80) x = (x+1)%5; // Xuong
        } else if (key == 13) { // Enter
            string val;
            switch(x){
            case 0:
                cout << "Nhap gia tri: "; cin >> val;
                pushLeft(val);
                break;
            case 1:
                cout << "Nhap gia tri: "; cin >> val;
                pushRight(val);
                break;
            case 2: popLeft(); break;
            case 3: popRight(); break;
            case 4: n = 0; break;
            }
        }
    }
    return 0;
}

