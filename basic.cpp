#include <vector>
#include <iostream>
using namespace std;

vector<double> compute_vector_crossings(vector<double>, vector<double>);
double compute_vector_dot_products(vector<double>, vector<double>);
vector<double> fill_vector(void);
void print_vector(vector<double>);

int main(){
    vector<double> a,b,c;
    double d;
    a = fill_vector();
    b = fill_vector();
    c = compute_vector_crossings(a,b);
    d = compute_vector_dot_products(a,b);
    print_vector(c);
    cout << "dot product: " << d << endl;
    return 1;
}

void print_vector(vector<double> vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
}

vector<double> fill_vector(void){
    double input;
    cout << "Enter 3 numbers: " << endl;
    cin >> input;
    vector<double> vec;
    int count = 0;
    while(count <= 2 ){
        vec.push_back(input);
        cin >> input;
        count ++;
    }
    return vec;
}

vector<double> compute_vector_crossings(vector<double> vec1, vector<double> vec2){
    vector<double> crossings;
    crossings.push_back(vec1[1] * vec2[2] - vec1[2] * vec2[1]);
    crossings.push_back(- vec1[0] * vec2[2] + vec1[2] * vec2[0]);
    crossings.push_back(vec1[0] * vec2[1] - vec1[1] * vec2[0]);
    return crossings;
}

double compute_vector_dot_products(vector<double> vec1, vector<double> vec2){
    double dots_prod;
    for (size_t i = 0; i < vec1.size();i++){
        dots_prod += (vec1[i]*vec2[i]);
    }
    return dots_prod;
}

