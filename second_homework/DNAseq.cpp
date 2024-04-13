#include "DNAseq.h"

DNAseq::DNAseq( void )
{
	this->length = 0;
	this->sequence = nullptr;
}

DNAseq::DNAseq( string sequence )
{
	int i;
	for (i = 0; i < sequence.length(); i++)

	this->length = i;

}