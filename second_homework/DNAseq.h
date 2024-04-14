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

		// helper member functions
		string sequenceAsString( void ) const;
		Nucleotide *getSequence( void ) const;
		int getLength( void ) const;

		// operator overlaods   // Change return types later
		bool operator<=( const DNAseq& rhs ) const;
		DNAseq operator*( unsigned int number ) const;
		int operator%( Nucleotide nucleotide ) const; // without const keyword, main.cpp didn't like this definition, it might have been worked, but yes...
		DNAseq operator!( void ) const;
		DNAseq& operator=( const DNAseq& rhs );
		DNAseq operator+( const DNAseq& rhs ) const;
		DNAseq operator-( const DNAseq& rhs) const;
		DNAseq& operator+=(const DNAseq& rhs);
};

DNAseq operator+( Nucleotide nucleotide, const DNAseq& rhs );
ostream& operator<<(ostream& os, const DNAseq& dna);

#endif /* end of DNASEQ_H */