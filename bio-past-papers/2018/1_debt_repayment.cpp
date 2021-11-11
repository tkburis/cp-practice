// https://www.olympiad.org.uk/papers/2018/bio/bio18-exam.pdf

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int interest_perc, repayment_perc;
    cin >> interest_perc >> repayment_perc;
    int curr_debt = 10000, amount_repaid = 0;
    while (curr_debt > 0) {
        curr_debt += ceil((float)(curr_debt * interest_perc)/100);
        int to_repay = ceil((float)(curr_debt * repayment_perc)/100);
        to_repay = min(max(to_repay, 5000), curr_debt);
        curr_debt -= to_repay;
        amount_repaid += to_repay;
    }
    cout << fixed << setprecision(2) << (float)amount_repaid/100 << endl;
    return 0;
}
