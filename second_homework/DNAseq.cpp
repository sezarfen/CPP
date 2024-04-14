#include "DNAseq.h"

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
		for(int k = 0; k < this->length; k++)
		{
			if (this->sequence[k] == A)
				newSequence.push_back('A');
			else if (this->sequence[k] == C)
				newSequence.push_back('C');
			else if (this->sequence[k] == G)
				newSequence.push_back('G');
			else
				newSequence.push_back('T');
		}
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
		return ;
	
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
}

DNAseq DNAseq::operator+( const DNAseq& rhs) const
{
	// let's see if the first nucleotide is in the rhs
	
	/*
	if (rhs.length == 0) consider this situation with respect to + operator
		return (DNAseq())
	*/
	
	Nucleotide toFind = rhs.sequence[0];
	bool isContain = false;
	for (int i = 0; i < this->length; i++)
	{
		if (toFind == this->sequence[i])
			isContain = true;
	}
	
	string newSequence;

	// first case (a)
	if (isContain)
	{
		int i = 0;
		while (this->sequence[i] != toFind)
		{ // add untill first occurence
			if (this->sequence[i] == A)
				newSequence.push_back('A');
			else if (this->sequence[i] == T)
				newSequence.push_back('T');
			else if (this->sequence[i] == G)
				newSequence.push_back('G');
			else // C
				newSequence.push_back('C');
			i++;
		}
		
		// add that occurence
		if (this->sequence[i] == A)
			newSequence.push_back('A');
		else if (this->sequence[i] == T)
			newSequence.push_back('T');
		else if (this->sequence[i] == G)
			newSequence.push_back('G');
		else // C
			newSequence.push_back('C');
		i++;
		
		
		// insert just after first occurence
		for (int k = 0; k < rhs.length; k++)
		{
			if (rhs.sequence[i] == A)
				newSequence.push_back('A');
			else if (rhs.sequence[i] == T)
				newSequence.push_back('T');
			else if (rhs.sequence[i] == G)
				newSequence.push_back('G');
			else // C
				newSequence.push_back('C');
		}
		
		// add the rest of the lhs
		while (i < this->length)
		{
			if (this->sequence[i] == A)
				newSequence.push_back('A');
			else if (this->sequence[i] == T)
				newSequence.push_back('T');
			else if (this->sequence[i] == G)
				newSequence.push_back('G');
			else // C
				newSequence.push_back('C');
			i++;
		}

	}
	else // second case (b)
	{
		// concatination operation
		for (int i = 0; i < this->length; i++) // adding lhs
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
		for (int i = 0; i < this->length; i++) // adding rhs
		{			
			if (rhs.sequence[i] == A)
				newSequence.push_back('A');
			else if (rhs.sequence[i] == T)
				newSequence.push_back('T');
			else if (rhs.sequence[i] == G)
				newSequence.push_back('G');
			else // C
				newSequence.push_back('C');
		}
	}
	return (DNAseq(newSequence));
}