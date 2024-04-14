#include "DNAseq.h"

// core dumped cases
// dna6 = dna6 + dna4 + dna2*2 - dna2 + (C + dna4) + (dna6 - dna6*4): TTTTTACTA
/*
	free(): double free detected in tcache 2
	Aborted (core dumped)
*/

DNAseq::DNAseq( void )
{
	this->length = 0;
	this->sequence = nullptr;
}

DNAseq::DNAseq( string sequence )
{
	if (sequence.length() == 0)
		return ;
	this->sequence = new Nucleotide[sequence.length()];
	int i;
	for (i = 0; i < sequence.length(); i++)
	{
		if (sequence[i] == 'A')
			this->sequence[i] = A;
		else if (sequence[i] == 'C')
			this->sequence[i] = C;
		else if (sequence[i] == 'G')
			this->sequence[i] = G;
		else
			this->sequence[i] = T;
	}
	this->length = i;
}

DNAseq::DNAseq( const DNAseq& rhs )
{
	this->length = rhs.length;
	
	// DEEP COPY
	if (this->sequence != nullptr)
		delete[] this->sequence;
	this->sequence = new Nucleotide[this->length];
	for (int i = 0; i < this->length; i++)
	{
		this->sequence[i] = rhs.sequence[i];
	}
}

DNAseq::~DNAseq( void )
{
	this->length = 0; // just to be sure...
	delete[] this->sequence;
}

string DNAseq::sequenceAsString( void ) const
{
	string sequenceString;

	for (int i = 0; i < this->length; i++)
	{
			if (this->sequence[i] == A)
				sequenceString.push_back('A');
			else if (this->sequence[i] == C)
				sequenceString.push_back('C');
			else if (this->sequence[i] == G)
				sequenceString.push_back('G');
			else
				sequenceString.push_back('T');
	}
	return (sequenceString);
}

Nucleotide *DNAseq::getSequence( void ) const
{
	return (this->sequence);
}

int DNAseq::getLength() const
{
	return (this->length);
}

char DNAseq::getNucleotideAsChar( int index ) const
{
	// it assumes the index is exists
	switch (this->sequence[index])
	{
	case A:
		return ('A');
	case T:
		return ('T');
	case G:
		return ('G');
	default:
		return ('C');
	}
}

bool DNAseq::operator<=( const DNAseq& rhs ) const
{
	// this pointer will be lhs here
	// when we point the first same occurance we can go forward to see it
	int i = 0;
	int j = 0;
	while (i < rhs.length)
	{
		while (i < rhs.length && rhs.sequence[i + j] == this->sequence[j])
		{ 
			j++;
		}
		// if this subsequence is totally equal j and this->length must be equal to each other
		if (j != this->length)
		{
			i += j;
			j = 0;
		}
		else
			return (true);
		i++;
	}
	return (false);
}

DNAseq DNAseq::operator*( unsigned int number ) const
{
	string newSequence;

	for (unsigned int i = 0; i < number; i++)
	{
		newSequence += sequenceAsString();
	}
	return (DNAseq(newSequence)); // it might cause a segmentation fault
}

int DNAseq::operator%( Nucleotide nucleotide ) const
{
	int count = 0;

	for (int i = 0; i < this->length; i++)
	{
		if (this->sequence[i] == nucleotide)
			count++;
	}
	return (count);
}

DNAseq DNAseq::operator!( void ) const
{
	string newSequence;

	for (int i = 0; i < this->length; i++)
	{
		if (this->sequence[i] == A)
			newSequence.push_back('T');
		else if (this->sequence[i] == T)
			newSequence.push_back('A');
		else if (this->sequence[i] == G)
			newSequence.push_back('C');
		else // C
			newSequence.push_back('G');
	}
	return (DNAseq(newSequence)); // it might cause a segmentation fault, check later
}

// copy assignment operator
DNAseq& DNAseq::operator=( const DNAseq& rhs )
{
	if (this == &rhs) // they passed the same object
		return *this;
	
	// If our sequence is already exists.
	if (this->sequence != nullptr)
		delete[] this->sequence;
	
	this->length = rhs.length;

	// DEEP copy
	this->sequence = new Nucleotide[this->length];
	for (int i = 0; i < this->length; i++)
	{
		this->sequence[i] = rhs.sequence[i];
	}
	return (*this);
}

DNAseq operator+( const DNAseq& lhs, const DNAseq& rhs )
{
	// let's see if the first nucleotide is in the rhs
	
	/*// check rhs and lhs length if they are equal to zero there might be a problem
	if (rhs.length == 0) consider this situation with respect to + operator
		return (DNAseq())
	*/

	Nucleotide* lsequence = lhs.getSequence();
	Nucleotide* rsequence = rhs.getSequence();
	int left_len = lhs.getLength();
	bool isContain = false;

	for (int i = 0; i < left_len; i++)
	{
		if (rsequence[0] == lsequence[i])
			isContain = true;
	}

	string newSequence;

	if (isContain)
	{
		int i = 0;
		while (lsequence[i] != rsequence[0])
			newSequence.push_back(lhs.getNucleotideAsChar(i++));
		// first occurance, lets also add this one
		newSequence.push_back(lhs.getNucleotideAsChar(i++));
		newSequence += rhs.sequenceAsString();
		while (i < left_len)
			newSequence.push_back(lhs.getNucleotideAsChar(i++));
	}
	else // we just need to print lhs + rhs
	{
		newSequence += lhs.sequenceAsString();
		newSequence += rhs.sequenceAsString();
	}
	return (DNAseq(newSequence));
}

DNAseq operator+( Nucleotide nucleotide, const DNAseq& rhs )
{
	string newSequence;

	// First append the nucleotide
	if (nucleotide == A)
		newSequence.push_back('A');
	else if (nucleotide == T)
		newSequence.push_back('T');
	else if (nucleotide == G)
		newSequence.push_back('G');
	else
		newSequence.push_back('C');

	// We can 't reach rhs private attributes from here
	newSequence += rhs.sequenceAsString();
	return (DNAseq(newSequence));

}

// OF COURSE CHECK THIS ONE XD
DNAseq DNAseq::operator-( const DNAseq& rhs ) const
{
	bool isContain = rhs <= *this;
	string newSequence;

	if (isContain) // remove case
	{
		// add until find it, then skip the occurence and add the rest
		int i = 0;
		int j = 0;
		while (i < this->length)
		{
			if (this->sequence[i + j] == rhs.sequence[j])
			{
				if (this->sequence[i] == A)
					newSequence.push_back('A');
				else if (this->sequence[i] == T)
					newSequence.push_back('T');
				else if (this->sequence[i] == G)
					newSequence.push_back('G');
				else // C
					newSequence.push_back('C');
			}
			while (i + j < this->length && this->sequence[i + j] ==  rhs.sequence[j])
			{
				j++;
			}
			if (j == rhs.length)
			{
				i += j;
				break;
			}
			else // if we couldn't find it
			{
				int k = i + j;
				while (i < k)
				{
					if (this->sequence[i] == A)
						newSequence.push_back('A');
					else if (this->sequence[i] == T)
						newSequence.push_back('T');
					else if (this->sequence[i] == G)
						newSequence.push_back('G');
					else // C
						newSequence.push_back('C');
					i++; // might cause a problem, let's check this later
				}
				j = 0;
			}
			i++;
		}
	}
	else // just return the lhs sequence (this)
	{
		newSequence = this->sequenceAsString();
	}
	return (DNAseq(newSequence));
}

DNAseq& DNAseq::operator+=( const DNAseq& rhs ) // check this one later
{
	*this = *this + rhs;
	return (*this);
}

ostream& operator<<(ostream& os, const DNAseq& dna)
{
	os << dna.sequenceAsString();
	return (os);
}