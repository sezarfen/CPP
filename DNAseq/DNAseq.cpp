#include "DNAseq.h"

DNAseq::DNAseq( void )
{
	this->length = 0;
	this->sequence = nullptr;
}

DNAseq::DNAseq( string sequence )
{
	if (sequence.length() == 0)
	{
		this->length = 0;
		this->sequence = nullptr;
		return ;
	}
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
	this->length = 0;
	delete[] this->sequence;
}

string DNAseq::sequenceAsString( void ) const
{
	string sequenceString = "";

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

bool operator<=( const DNAseq& lhs, const DNAseq& rhs )
{
	string leftSeq = lhs.sequenceAsString();
	string rightSeq = rhs.sequenceAsString();
	
	if (rightSeq.find(leftSeq) != string::npos)
		return (true);
	else
		return (false);
}

DNAseq DNAseq::operator*( unsigned int number ) const
{
	if (this->length == 0 || number <= 0)
		return (DNAseq());

	string newSequence = "";
	for (unsigned int i = 0; i < number; i++)
	{
		newSequence += sequenceAsString();
	}
	return (DNAseq(newSequence));
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
	string newSequence = "";

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
	return (DNAseq(newSequence));
}

DNAseq & DNAseq::operator=( const DNAseq& rhs )
{
	if (this == &rhs)
		return *this;
	
	if (this->sequence != nullptr)
		delete[] this->sequence;
	
	this->length = rhs.length;

	this->sequence = new Nucleotide[this->length];
	for (int i = 0; i < this->length; i++)
	{
		this->sequence[i] = rhs.sequence[i];
	}
	return (*this);
}

DNAseq operator+( const DNAseq& lhs, const DNAseq& rhs )
{
	if (lhs.getLength() == 0 && rhs.getLength() == 0)
		return (DNAseq());
	else if (lhs.getLength() == 0)
		return (DNAseq(rhs.sequenceAsString()));
	else if (rhs.getLength() == 0)
		return (DNAseq(lhs.sequenceAsString()));

	Nucleotide* lsequence = lhs.getSequence();
	Nucleotide* rsequence = rhs.getSequence();
	int left_len = lhs.getLength();
	
	bool isContain = false;

	for (int i = 0; i < left_len; i++)
	{
		if (rsequence[0] == lsequence[i])
		{
			isContain = true;
			break;
		}
	}

	string newSequence = "";

	if (isContain)
	{
		int i = 0;
		while (lsequence[i] != rsequence[0])
		{
			newSequence.push_back(lhs.getNucleotideAsChar(i));
			i++;
		}
		newSequence.push_back(lhs.getNucleotideAsChar(i));
		i++;
		newSequence += rhs.sequenceAsString();
		while (i < left_len)
		{
			newSequence.push_back(lhs.getNucleotideAsChar(i));
			i++;
		}
	}
	else
	{
		newSequence += lhs.sequenceAsString();
		newSequence += rhs.sequenceAsString();
	}
	return (DNAseq(newSequence));
}

DNAseq operator+( Nucleotide nucleotide, const DNAseq& rhs )
{
	string newSequence = "";

	if (nucleotide == A)
		newSequence.push_back('A');
	else if (nucleotide == T)
		newSequence.push_back('T');
	else if (nucleotide == G)
		newSequence.push_back('G');
	else
		newSequence.push_back('C');

	newSequence += rhs.sequenceAsString();
	return (DNAseq(newSequence));

}

DNAseq operator-( const DNAseq& lhs, const DNAseq& rhs )
{ // lhs - rhs
	bool isContain = (rhs <= lhs);
	string newSequence = "";

	if (isContain)
	{
		string rightSeq = rhs.sequenceAsString();
		string leftSeq = lhs.sequenceAsString();

		int i = 0;
		int pos = leftSeq.find(rightSeq);
		while (i < leftSeq.length())
		{
			if (i == pos)
				i += rightSeq.length();
			if (i < leftSeq.length())
				newSequence.push_back(leftSeq[i]);
			i++;
		}
	}
	else
	{
		newSequence = lhs.sequenceAsString();
	}
	return (DNAseq(newSequence));
}

DNAseq& DNAseq::operator+=( const DNAseq& rhs )
{
	*this = *this + rhs;
	return (*this);
}

ostream& operator<<(ostream& os, const DNAseq& dna)
{
	os << dna.sequenceAsString();
	return (os);
}