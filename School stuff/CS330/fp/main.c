#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <string.h>


#define PAGE_SIZE	256
#define PAGE_ENTRIES	256
#define TLB_ENTRIES	16
#define FRAME_SIZE	256
#define NUMBER_FRAMES   256
#define PHYSICAL_SIZE   65536
#define VM_SIZE		65536

using namespace std;

// Check if TLB Hit has occured, return tlb entry
int tlbCheck(int pageTableNum, int tlb[][2]);
// Update TLB by evicting most recently used entry 
void eviction(int tlb[][2], int pageTableNum, int frameNumber,int tlbFront, int tlbBack);
// Fill tables with initial values
void fillTables(int tlb[][2], int pTab[]);
// return page table entry
int pageTableCheck(int pageTableNum, int pTab[]);


int main(int argc, char *argv[]){
	// tlb :: [0] == Tag, [1] == physical page number
	int tlb[TLB_ENTRIES][2], pageTable[PAGE_ENTRIES];

	int logicalAddress, offset, pageNumber,frameNumber, physicalAddress, valueAt
		, tlbFront = -1, tlbBack = -1, pageAddress
		, memIndex = 0;
	
	char memory[PHYSICAL_SIZE], backingData[VM_SIZE];
	
	// Input Files
	ifstream file("Addresses.txt", fstream::in);
	ifstream backingStore("BACKING_STORE.bin", fstream::in);
	string buffer;

	backingStore.read(backingData, VM_SIZE);

	fillTables(tlb, pageTable);

	// Retrieve lines containing logical addresses
	while(getline(file,buffer)){
		logicalAddress = atoi(buffer.c_str());
		// Offset found using a mask of 255
		offset = logicalAddress & 255;
		// Page number found using a mask of 65280 then right shifted 8
		pageNumber = (logicalAddress & 65280) >> 8;
		// Check for corresponding frameNumber in TLB
		frameNumber = tlbCheck(pageNumber, tlb);
	
		//TLB Hit
		if(frameNumber != -1){
			physicalAddress = frameNumber + offset;
			valueAt = memory[physicalAddress];
		//TLB Miss
		}else{
			//Check page table for frame number
			frameNumber = pageTableCheck(pageNumber, pageTable);

			//Page Table Hit
			if(frameNumber != -1){
				//Compute physical address and update TLB
				physicalAddress = frameNumber + offset;
				eviction(tlb, pageNumber, frameNumber, tlbFront, tlbBack);
				valueAt = memory[physicalAddress];
			//Page Fault
			}else{
				//Move page from backing store into page frame
				pageAddress = pageNumber * PAGE_SIZE;
				if(memIndex != -1){
					memcpy(memory+memIndex, backingData + pageAddress, PAGE_SIZE);
					frameNumber = memIndex;
					physicalAddress = frameNumber + offset;
					valueAt = memory[physicalAddress];
					pageTable[pageNumber] = memIndex;
					eviction(tlb, pageNumber, frameNumber, tlbFront, tlbBack);
					//Increment memIndex if not full
					if (memIndex < PHYSICAL_SIZE - FRAME_SIZE) {
						memIndex += FRAME_SIZE;
					//Memory is full
					} else {
							memIndex = -1;
						}
					} else{

				}
			}
			//Output to screen Logical, physical, and value.
			cout << "Logical: " << logicalAddress;
			cout << "   Physical: " << physicalAddress;
			cout << "   Value: " << valueAt << endl;
		}
	}
}

//Fill with initial values
void fillTables(int tlb[][2], int pTab[]){
	for(int i = 0; i < TLB_ENTRIES; i++){
		tlb[i][0] = -1;
		tlb[i][1] = -1;
	}
	for(int i = 0; i < PAGE_ENTRIES; i++){
		pTab[i] = -1;
	}
}

//Return value in tlb or -1 if failed
int tlbCheck(int pageTableNumber, int tlb[][2]){
	for(int i = 0; i < TLB_ENTRIES; i++){
		if(pageTableNumber == tlb[i][0]){
			return tlb[i][1];
		}
	}
	return -1;
}

//Return value in page table
int pageTableCheck(int pageNumber, int pTab[]){
	return pTab[pageNumber];
}

//Update the tlb using a circular queue implementation
void eviction(int tlb[][2], int pageNumber, int frameNumber, int tlbFront, int tlbBack){
	if (tlbFront == -1){   
		tlbFront = 0;
		tlbBack = 0;
		tlb[tlbBack][0] = pageNumber;
		tlb[tlbBack][1] = frameNumber;
	}
	else{
		tlbFront = (tlbFront + 1) % TLB_ENTRIES;
		tlbBack = (tlbBack + 1) % TLB_ENTRIES;
		tlb[tlbBack][0] = pageNumber;
		tlb[tlbBack][1] = frameNumber;
	}
}
