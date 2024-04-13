#ifndef DNASEQ_H
# define DNASEQ_H

#include <iostream>
using namespace std;

enum Nucleotide {A, C, G, T};

class DNAseq
{
	private:
		int length; // represents the # of nucleotides in the DNA sequence.
		Nucleotide *sequence;

	public:
		DNAseq( void );
		DNAseq( string sequence ); // Assume that the string parameter does not contain any invalid value, but it might be empty.
		DNAseq( const DNAseq& rhs ); // Deep Copy
		~DNAseq( void ); // deletes all dynamically allocated memory and return them back to the heap

		// operator overlaods   // Change return types later
		bool operator<=( const DNAseq& rhs );
		void operator*( const DNAseq& rhs );
		bool operator%( const DNAseq& rhs );
		bool operator!( void );
		DNAseq& operator=( const DNAseq& rhs );
		DNAseq& operator+( const DNAseq& rhs );
		bool operator+( const Nucleotide* nucleotide ); // check this later
		DNAseq operator-( const DNAseq& rhs );
		bool operator+=( const DNAseq& rhs );
		bool operator<<( const DNAseq& rhs );
};

ostream& operator<<(ostream& os, const DNAseq& dna)
{
	// do something
}

#endif /* end of DNASEQ_H */