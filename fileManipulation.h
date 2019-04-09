bool getFileSize( std::string path, unsigned int &size){
	//in case of error:
		//size = 0
		//return false;
	size = 0;

	// get the file stream
	FILE* pFile = fopen( path.c_str(), "rb" );
	if(pFile == NULL){
		perror("Could not open the file. Error");
		return false;
	}

	// set the file pointer to end of file
	int ret = fseek( pFile, 0, SEEK_END );
	if(ret < 0){
		perror("ERRORE:\n");
		return false;
	}

	// get the file size	 
	long int tmp = ftell(pFile);
	if(tmp < 0){
		perror("ftell() Error:");
		return false;
	}

	size = tmp;

	// close file
	ret = fclose( pFile );
	if(ret < 0){
		perror("ERROR:\n");
		size = 0;
		return false;
	}

	return true;
}
