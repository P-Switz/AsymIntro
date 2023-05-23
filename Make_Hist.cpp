//Making a histogram
//Working through TH1F and TH2F
//This just draws it, doesn't write/save it

void Make_Hist() {
	//make a simple histogram
	//PHASE SPACE: uniformly sample in cos(theta), then convert back to theta and plot that
	//randomly generatingevents often results in a phase space distribution
	

	//define the histogram
	TH1F*h1 = new TH1F("h1","Phase Space",180,0,180); //arguments are: name, title, number of bins, low, high

	TH1F*h2 = new TH1F("h2","Energy",180,0,180);

	TH2D*h3 = new TH2D("h3","TITLE",1800,0,1800,1800,0,1800);

	Double_t costheta, theta, energy;

	//loop over large number of events
	for (int i=0; i<100000; i++) {
		costheta = gRandom->Uniform(-1,1); //picks random number between -1 and 1
		theta = acos(costheta); //tale arc cosine
		energy = 200/(1+(200/938.28)*(1-cos(theta)));
		theta*=180/3.14; //convert to degrees
		h1->Fill(theta); //fill the histogram
		
		h2->Fill(energy);
	
		h3->Fill(theta,energy);
	}
	
/*	h2->Draw(); //draw the histogram to see what has happened*/
	h3->Draw();
}
