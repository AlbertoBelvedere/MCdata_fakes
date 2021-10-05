#include "SIGfakes.h"
#include <iostream>
#include <TFile.h>
#include <TString.h>
#include <TTree.h>

int main(int argc, char* argv[]){
	
	if(argc != 2){
		std::cout << "Errore, passare il percorso del file da analizzare" << std::endl;
		exit(-1);
	}
	TString fname = argv[1];
	TFile* rootfile = TFile::Open(fname);
	if( !rootfile->IsOpen() ){
		std::cout << "Errore nella lettura del file" << std::endl;
		exit(-1);
	}
	std::cout << "reading data from" << fname << std::endl;
	
	TDirectoryFile* dir = (TDirectoryFile*) rootfile->Get("tnpAna");
	TTree* tree = (TTree*) dir->Get("fitter_tree");
	if(!tree){
		std::cout << "Errore nella lettura del tree" << std::endl;
		exit(-1);
	}
	SIGfakes analyser(tree);	
	analyser.Loop();
	
	rootfile->Close();
	
	return 0;
}
