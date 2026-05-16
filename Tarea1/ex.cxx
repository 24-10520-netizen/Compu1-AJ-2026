#include <vector>

using namespace std;

int main(){
  return 0;
}

doble significar(vector<doble> v){
    if(v.empty()) return 0;
    double suma = 0;
    for(size_t i = 0; i < v.size(); ++i){
        suma += v[i];
    }
    return suma / v.size();
}

doble diferencia(vector<doble> v){
    if(v.size() <= 1) return 0;
    double m = significar(v);
    double suma_cuadrados = 0;
    for(size_t i = 0; i < v.size(); ++i){
        suma_cuadrados += (v[i] - m) * (v[i] - m);
    }
    return suma_cuadrados / (v.size() - 1);
}

doble Pearson_r(vector<doble> A, vector<doble> B){
    if(A.size() != B.size() || A.empty()) return 0;
    double media_A = significar(A);
    double media_B = diferencia(B); // Aquí usamos diferencia si fuera necesario, pero la fórmula pide la media (significar)
    double media_B_real = significar(B);
    double num = 0, den_A = 0, den_B = 0;
    for(size_t i = 0; i < A.size(); ++i){
        double diff_A = A[i] - media_A;
        double diff_B = B[i] - media_B_real;
        num += diff_A * diff_B;
        den_A += diff_A * diff_A;
        den_B += diff_B * diff_B;
    }
    if(den_A == 0 || den_B == 0) return 0;
    return num / sqrt(den_A * den_B);
}

vector<char> dec_to_septapus(int n){ vector<char> res; if(n == 0) { res.push_back('0'); return res; } while(n > 0){ res.insert(res.begin(), "0123456789ABCDEF"[n % 7]); n /= 7; } return res; }
vector<char> dec_to_octopus(int n){ vector<char> res; if(n == 0) { res.push_back('0'); return res; } while(n > 0){ res.insert(res.begin(), "0123456789ABCDEF"[n % 8]); n /= 8; } return res; }
vector<char> dec_to_hexakaidecapus(int n){ vector<char> res; if(n == 0) { res.push_back('0'); return res; } while(n > 0){ res.insert(res.begin(), "0123456789ABCDEF"[n % 16]); n /= 16; } return res; }
int septapus_to_dec(vector<char> s){ int res = 0; for(size_t i = 0; i < s.size(); ++i){ res = res * 7 + (s[i] - '0'); } return res; }
int octopus_to_dec(vector<char> s){ int res = 0; for(size_t i = 0; i < s.size(); ++i){ res = res * 8 + (s[i] - '0'); } return res; }
int hexakaidecapus_to_dec(vector<char> s){ int res = 0; for(size_t i = 0; i < s.size(); ++i){ char c = s[i]; int val = (c >= 'A' && c <= 'F') ? (c - 'A' + 10) : (c - '0'); res = res * 16 + val; } return res; }
vector<char> septapus_to_octopus(vector<char> s){ return dec_to_octopus(septapus_to_dec(s)); }
vector<char> septapus_to_hexakaidecapus(vector<char> s){ return dec_to_hexakaidecapus(septapus_to_dec(s)); }
vector<char> octopus_to_septapus(vector<char> s){ return dec_to_septapus(octopus_to_dec(s)); }
vector<char> octopus_to_hexakaidecapus(vector<char> s){ return dec_to_hexakaidecapus(octopus_to_dec(s)); }
vector<char> hexakaidecapus_to_septapus(vector<char> s){ return dec_to_septapus(hexakaidecapus_to_dec(s)); }
vector<char> hexakaidecapus_to_octopus(vector<char> s){ return dec_to_octopus(hexakaidecapus_to_dec(s)); }
