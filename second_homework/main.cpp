#include <iostream>
#include <string>
#include "DNAseq.h"
using namespace std;

void displayCounts(const DNAseq & dna)
{
    int countA = dna % A;
    int countC = dna % C;
    int countG = dna % G;
    int countT = dna % T;

    cout << "A: ";
    for (int i = 0; i < countA; i++)
    {
        cout << "*";
    }
    cout << endl;

    cout << "C: ";
    for (int i = 0; i < countC; i++)
    {
        cout << "*";
    }
    cout << endl;

    cout << "G: ";
    for (int i = 0; i < countG; i++)
    {
        cout << "*";
    }
    cout << endl;

    cout << "T: ";
    for (int i = 0; i < countT; i++)
    {
        cout << "*";
    }
    cout << endl;
}

int main() {

    string str_sequence;

    cout << "Enter the first DNAseq sequence: " << endl;
    cin >> str_sequence;
    DNAseq dna1(str_sequence);

    cout << "Enter the second DNAseq sequence: " << endl;
    cin >> str_sequence;
    DNAseq dna2(str_sequence);

    cout << "dna1 is: " << dna1 << endl;
    cout << "dna2 is: " << dna2 << endl;

    if (dna1 <= dna2)
        cout << "dna1 is a subsequence of dna2."  << endl;
    else
        cout << "dna1 is not a subsequence of dna2."  << endl;

    cout << "dna1's nucleotide counts: " << endl;
    displayCounts (dna1);
    cout << "dna2's nucleotide counts: " << endl;
    displayCounts (dna2);

    DNAseq dna3 (dna1 + dna2);
    cout << "dna1: " << dna1 << endl;
    cout << "dna2: " << dna2 << endl;
    cout << "dna3 (dna1 + dna2): " << dna3 << endl;

    DNAseq dna4;
    dna4 = dna1 - dna2;
    cout << "dna4 = dna1 - dna2: " << dna4 << endl;

    cout << "dna1's complement: " << !dna1 << endl;

    dna1 = dna1 * 3;
    cout << "dna1 = dna1 * 3: " << dna1 << endl;

    int c = dna4 % A;
    cout << "dna4 % A: " << c << endl;

    DNAseq dna5 = A + (T + (G + dna2));
    cout << "dna5 = A + (T + (G + dna2)): " << dna5 << endl;

    DNAseq dna6;
    dna6 = dna6 + dna4 + dna2*2 - dna2 + (C + dna4) + (dna6 - dna6*4);
    cout << "dna6 = dna6 + dna4 + dna2*2 - dna2 + (C + dna4) + (dna6 - dna6*4): " << dna6 <<endl;
    cout << "dna2: " << dna2 << endl;
    cout << "dna4: " << dna4 << endl;

    dna6 = T + dna1 + !dna1;
    cout << "dna6 = T + dna1 + !dna1: " << dna6 << endl;

    dna6 = dna1 = dna2 = dna4;
    cout << "After dna6 = dna1 = dna2 = dna4" << endl;
    cout << "dna1: " << dna1 << endl;
    cout << "dna2: " << dna2 << endl;
    cout << "dna4: " << dna4 << endl;
    cout << "dna6: " << dna6 << endl;

    dna6 = dna6;
    cout << "dna6 = dna6: " << dna6 << endl;

    DNAseq dna7;
    dna7 += dna4 += dna2;
    cout << "After dna7 += dna4 += dna2" << endl;
    cout << "dna2: " << dna2 << endl;
    cout << "dna4: " << dna4 << endl;
    cout << "dna7: " << dna7 << endl;

    DNAseq dna8 ("");
    cout << "(dna8 - dna4 + dna4) - dna8 + dna8: " << (dna8 - dna4 + dna4) - dna8 + dna8;



    return 0;

}