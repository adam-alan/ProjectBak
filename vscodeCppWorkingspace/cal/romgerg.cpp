# include <iostream>

# include <cmath>

double f(double x){
    return (sqrt(4 - sin(x) * sin(x)));
}


inline double be_pow(std::size_t x,std::size_t y){
    int ans = 1;
    while (y != 0)
    {
        ans = ((y & 1) == 1) ? ans * x : ans;
        y >>= 1;
        x *= x;
    }
    return ans;
}

double cal_t(std::size_t k){
    if (k < 1){
        return -1;
    }
    if (k ==1){
        
    }
}

double romberg(double (*f)(double),double a,double b,double wuch){
    double t[10][10];
    double h = b - a;
    t[0][0] = (h / 2 ) * (f(a) + f(b));
    std::size_t k = 1;


    do{
        t[k][0] = (b - a) / 2;
        for (int m = 1; m <= k; m++)
        {
            t[k][m] = (be_pow(4, m) / (be_pow(4, m) - 1)) * t[k + 1][m - 1] - ( 1 / (be_pow(4, m) - 1) ) * t[k][m - 1];
        }
        k += 1;
    } while ( (t[0][k] - t[0][k - 1]) < wuch);
    return 3.21;
}


int main(){
    std::cout << be_pow(10, 3) << std::endl;
    return 0;
}
