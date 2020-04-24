TH1D*h1Mass[4],*angClust[4];  TH1D*tof1M[4],*h1inv3; TH2D*tof1IDvM[4];
TH1D*h1Eclust[4],*prAng[4];   TH1D*tof1S[4],*mnfit5; TH1D*h1rate2,*h1piAng;
TH1D*h1P[4],*tof1ID[4];       TH1D*h1clusM,*mnfit6; TH1D*h1rate3,*h1diff3;
std::string pname[]={"pNoCut","pKpi2Cut","ptof1Cut","pAngCut"};
std::string Ename[]={"ENoCut","EKpi2Cut","Etof1Cut","EAngCut"};
std::string Mname[]={"MNoCut","MKpi2Cut","Mtof1Cut","MAngCut"};
std::string tf1IDname[]={"tof1IDNoCut","tof1IDKpi2Cut","tof1IDtof1Cut","tof1IDAngCut"};
std::string tf1Mname[]={"tof1MNoCut","tof1MKpi2Cut","tof1Mtof1Cut","tof1AngCut"};
std::string tf1Sname[]={"tof1SNoCut","tof1SKpi2Cut","tof1Stof1Cut","tof1AngCut"};
std::string tf1vMname[]={"tof1vMNoCut","tof1vMKpi2Cut","tof1vMtof1Cut","tof1vMAngCut"};
std::string prAngname[]={"prAngNoCut","prAngKpi2Cut","prAngtof1Cut","prAngAngCut"};
std::string clustAngname[]={"clustAngNoCut","clustAngKpi2Cut","clustAngtof1Cut","clustAngAngCut"};
std::string crysNname[]={"crysNumNoCut","crysNumKpi2Cut","crysNumtof1Cut","crysNumAngCut"};
void plots(){
  TFile *tf1= new TFile("csiTofCut.root");
  for(int i=0; i<4; i++){
    angClust[i]=(TH1D*)tf1->Get(clustAngname[i].c_str());
    prAng[i]   =(TH1D*)tf1->Get(prAngname[i].c_str());
    h1Mass[i]  =(TH1D*)tf1->Get(Mname[i].c_str());
    h1Eclust[i]=(TH1D*)tf1->Get(Ename[i].c_str());
    h1P[i]     =(TH1D*)tf1->Get(pname[i].c_str());
    tof1ID[i]  =(TH1D*)tf1->Get(tf1IDname[i].c_str());
    tof1M[i]   =(TH1D*)tf1->Get(tf1Mname[i].c_str());
    tof1S[i]   =(TH1D*)tf1->Get(tf1Sname[i].c_str());
    tof1IDvM[i]=(TH2D*)tf1->Get(tf1vMname[i].c_str());
  }
  h1piAng=(TH1D*)tf1->Get(prAngname[3].c_str());
  gStyle->SetOptStat(0);
  TCanvas* c1 = new TCanvas("c1", " Testing Cooker: 1 ", 100, 100, 800, 650);
  c1->cd();
  h1Eclust[0]->SetTitle("Total cluster energy");
  h1Eclust[0]->GetXaxis()->SetTitle("Total Energy [GeV]");
  h1Eclust[0]->GetXaxis()->SetTitleSize(0.045);
  h1Eclust[0]->SetFillColor(kBlue);
  h1Eclust[0]->SetLineWidth(1);
  h1Eclust[0]->Draw("");

  h1Eclust[2]->SetLineWidth(1);
  h1Eclust[2]->SetFillColor(kRed);
  h1Eclust[2]->Draw("same");

  h1Eclust[1]->SetLineWidth(1);
  h1Eclust[1]->SetFillColor(kGreen);
  h1Eclust[1]->Draw("same");

  h1Eclust[3]->SetLineWidth(1);
  h1Eclust[3]->SetFillColor(kBeach);
  h1Eclust[3]->Draw("same");
  auto legend = new TLegend(0.1,0.7,0.48,0.9);
  legend->SetHeader("CsI(Tl):","C"); // option "C" allows to center the header
  legend->AddEntry(h1Eclust[0],"Good Gap Events","f");
  legend->AddEntry(h1Eclust[1],"P_{K_{#pi2}} cut","f");
  legend->AddEntry(h1Eclust[2],"extra TOF1 #geq 2","f");
  legend->AddEntry(h1Eclust[3],"P_{K_{#pi2}} and cos(#theta_{#pi^{+}#pi^{0}}) cut","f");
  legend->Draw();
  //c1->Write();
  // Invariant mass plots for all && 2 cluster events
  TCanvas* c2 = new TCanvas("c2", " Testing Cooker: 1 ", 100, 100, 800, 650);
  c2->cd();
  h1Mass[0]->SetTitle("Invariant mass of e^{+}e^{-}");
  h1Mass[0]->GetXaxis()->SetTitle("M_{e^{+}e^{-}}");
  h1Mass[0]->GetXaxis()->SetTitleSize(0.045);
  h1Mass[0]->SetFillColor(kBlue);
  h1Mass[0]->SetLineWidth(1);
  h1Mass[0]->Draw("");

  h1Mass[2]->SetLineWidth(1);
  h1Mass[2]->SetFillColor(kRed);
  h1Mass[2]->Draw("same");

  h1Mass[1]->SetLineWidth(1);
  h1Mass[1]->SetFillColor(kGreen);
  h1Mass[1]->Draw("same");

  h1Mass[3]->SetLineWidth(1);
  h1Mass[3]->SetFillColor(kBeach);
  h1Mass[3]->Draw("same");
  auto legend2 = new TLegend(0.1,0.7,0.48,0.9);
  legend2->SetHeader("CsI(Tl):","C"); // option "C" allows to center the header
  legend2->AddEntry(h1Mass[0],"M_{e^{+}e^{-}}: Good Gap Events","f");
  legend2->AddEntry(h1Mass[1],"M_{e^{+}e^{-}}: P_{K_{#pi2}} cut","f");
  legend2->AddEntry(h1Mass[2],"M_{e^{+}e^{-}}: extra TOF1 #geq 2","f");
  legend2->AddEntry(h1Mass[3],"M_{e^{+}e^{-}}: P_{K_{#pi2}} and cos(#theta_{#pi^{+}#pi^{0}}) cut","f");
  legend2->Draw();
  //c2->Write();

  TCanvas* c3 = new TCanvas("c3", " Testing Cooker: 1 ", 100, 100, 800, 650);
  c3->cd();
  h1P[0]->SetTitle("Gap momentum");
  h1P[0]->GetXaxis()->SetTitle("momentum [GeV]");
  h1P[0]->GetXaxis()->SetTitleSize(0.045);
  h1P[0]->SetFillColor(kBlue);
  h1P[0]->SetLineWidth(1);
  h1P[0]->Draw("");

  h1P[1]->SetLineWidth(1);
  h1P[1]->SetFillColor(kGreen);
  h1P[1]->SetFillStyle(3020);
  h1P[1]->Draw("same");

  h1P[2]->SetLineWidth(1);
  h1P[2]->SetFillColor(kRed);
  h1P[2]->Draw("same");

  h1P[3]->SetLineWidth(1);
  h1P[3]->SetFillColor(kBeach);
  h1P[3]->SetFillStyle(3144);
  h1P[3]->Draw("same");
  auto legend3 = new TLegend(0.1,0.7,0.48,0.9);
  legend3->SetHeader("CsI(Tl):","C"); // option "C" allows to center the header
  legend3->AddEntry(h1P[0],"Good Gap Events","f");
  legend3->AddEntry(h1P[1],"P_{K_{#pi2}} cut","f");
  legend3->AddEntry(h1P[2],"extra TOF1 #geq 2","f");
  legend3->AddEntry(h1P[3],"P_{K_{#pi2}} and cos(#theta_{#pi^{+}#pi^{0}}) cut","f");
  legend3->Draw();

  TCanvas* c4 = new TCanvas("c4", " Testing Cooker: 1 ", 100, 100, 800, 650);
  c4->cd();
  angClust[0]->SetTitle("Opening angle of 2 clusters");
  angClust[0]->GetXaxis()->SetTitle("cos(#theta_{e^{+}e^{-}})");
  angClust[0]->GetXaxis()->SetTitleSize(0.045);
  angClust[0]->SetFillColor(kBlue);
  angClust[0]->SetLineWidth(1);
  angClust[0]->Draw("");

  angClust[2]->SetLineWidth(1);
  angClust[2]->SetFillColor(kRed);
  angClust[2]->Draw("same");

  angClust[1]->SetLineWidth(1);
  angClust[1]->SetFillColor(kGreen);
  angClust[1]->Draw("same");

  angClust[3]->SetLineWidth(1);
  angClust[3]->SetFillColor(kBeach);
  angClust[3]->Draw("same");
  auto legend4 = new TLegend(0.1,0.7,0.48,0.9);
  legend4->SetHeader("CsI(Tl):","C"); // option "C" allows to center the header
  legend4->AddEntry(angClust[0],"Good Gap Events","f");
  legend4->AddEntry(angClust[1],"P_{K_{#pi2}} cut","f");
  legend4->AddEntry(angClust[2],"extra TOF1 #geq 2","f");
  legend4->AddEntry(angClust[3],"P_{K_{#pi2}} and cos(#theta_{#pi^{+}#pi^{0}}) cut","f");
  legend4->Draw();

  TCanvas* c5 = new TCanvas("c5", " Testing Cooker: 1 ", 100, 100, 800, 650);
  c5->cd();
  prAng[0]->SetTitle("Opening angle of tracked and cluster reconstructed particles");
  prAng[0]->GetXaxis()->SetTitle("cos(#theta_{track,clusPart})");
  prAng[0]->GetXaxis()->SetTitleSize(0.045);
  prAng[0]->SetFillColor(kBlue);
  prAng[0]->SetLineWidth(1);
  prAng[0]->Draw("");

  prAng[1]->SetLineWidth(1);
  prAng[1]->SetFillColor(kGreen);
  prAng[1]->Draw("same");

  prAng[2]->SetLineWidth(1);
  prAng[2]->SetFillColor(kRed);
  //prAng[2]->SetFillStyle(3020);
  prAng[2]->Draw("same");

  prAng[3]->SetLineWidth(1);
  prAng[3]->SetFillColor(kBeach);
  prAng[3]->SetFillStyle(3344);
  prAng[3]->Draw("same");
  auto legend5 = new TLegend(0.1,0.7,0.48,0.9);
  legend5->SetHeader("CsI(Tl):","C"); // option "C" allows to center the header
  legend5->AddEntry(prAng[0],"Good Gap Events","f");
  legend5->AddEntry(prAng[1],"P_{K_{#pi2}} cut","f");
  legend5->AddEntry(prAng[2],"extra TOF1 #geq 2","f");
  legend5->AddEntry(prAng[3],"P_{K_{#pi2}} and cos(#theta_{#pi^{+}#pi^{0}}) cut","f");
  legend5->Draw();

  TCanvas* c6 = new TCanvas("c6", " Testing Cooker: 1 ", 100, 100, 800, 650);
  c6->cd();
  tof1ID[0]->SetTitle("TOF1 ID");
  tof1ID[0]->GetXaxis()->SetTitle("TOF1 ID");
  tof1ID[0]->GetXaxis()->SetTitleSize(0.045);
  tof1ID[0]->SetFillColor(kBlue);
  tof1ID[0]->SetLineWidth(1);
  tof1ID[0]->Draw("");

  tof1ID[2]->SetLineWidth(1);
  tof1ID[2]->SetFillColor(kRed);
  tof1ID[2]->Draw("same");

  tof1ID[1]->SetLineWidth(1);
  tof1ID[1]->SetFillColor(kGreen);
  tof1ID[1]->Draw("same");

  tof1ID[3]->SetLineWidth(1);
  tof1ID[3]->SetFillColor(kBeach);
  tof1ID[3]->Draw("same");
  auto legend6 = new TLegend(0.1,0.7,0.48,0.9);
  legend6->SetHeader("CsI(Tl):","C"); // option "C" allows to center the header
  legend6->AddEntry(tof1ID[0],"Good Gap Events","f");
  legend6->AddEntry(tof1ID[1],"P_{K_{#pi2}} cut","f");
  legend6->AddEntry(tof1ID[2],"extra TOF1 #geq 2","f");
  legend6->AddEntry(tof1ID[3],"P_{K_{#pi2}} and cos(#theta_{#pi^{+}#pi^{0}}) cut","f");
  legend6->Draw();

  TCanvas* c7 = new TCanvas("c7", " Testing Cooker: 1 ", 100, 100, 800, 650);
  c7->cd();
  tof1M[0]->SetTitle("TOF1 multiplicity");
  tof1M[0]->GetXaxis()->SetTitle("TOF1 multiplicty");
  tof1M[0]->GetXaxis()->SetTitleSize(0.045);
  tof1M[0]->SetFillColor(kBlue);
  tof1M[0]->SetLineWidth(1);
  tof1M[0]->Draw("");

  tof1M[2]->SetLineWidth(1);
  tof1M[2]->SetFillColor(kRed);
  tof1M[2]->SetFillStyle(3144);
  tof1M[2]->Draw("same");

  tof1M[1]->SetLineWidth(1);
  tof1M[1]->SetFillColor(kGreen);
  tof1M[1]->Draw("same");

  tof1M[3]->SetLineWidth(1);
  tof1M[3]->SetFillColor(kBeach);
  tof1M[3]->Draw("same");
  auto legend7 = new TLegend(0.1,0.7,0.48,0.9);
  legend7->SetHeader("CsI(Tl):","C"); // option "C" allows to center the header
  legend7->AddEntry(tof1M[0],"Good Gap Events","f");
  legend7->AddEntry(tof1M[1],"P_{K_{#pi2}} cut","f");
  legend7->AddEntry(tof1M[2],"extra TOF1 #geq 2","f");
  legend7->AddEntry(tof1M[3],"P_{K_{#pi2}} and cos(#theta_{#pi^{+}#pi^{0}}) cut","f");
  legend7->Draw();

  TCanvas* c8 = new TCanvas("c8", " Testing Cooker: 1 ", 100, 100, 800, 650);
  c8->cd();
  tof1S[0]->SetTitle("TOF1 score");
  tof1S[0]->GetXaxis()->SetTitle("TOF1 score");
  tof1S[0]->GetXaxis()->SetTitleSize(0.045);
  tof1S[0]->SetFillColor(kBlue);
  tof1S[0]->SetLineWidth(1);
  tof1S[0]->Draw("");

  tof1S[2]->SetLineWidth(1);
  tof1S[2]->SetFillColor(kRed);
  tof1S[2]->Draw("same");

  tof1S[1]->SetLineWidth(1);
  tof1S[1]->SetFillColor(kGreen);
  tof1S[1]->Draw("same");

  tof1S[3]->SetLineWidth(1);
  tof1S[3]->SetFillColor(kBeach);
  tof1S[3]->Draw("same");
  auto legend8 = new TLegend(0.1,0.7,0.48,0.9);
  legend8->SetHeader("CsI(Tl):","C"); // option "C" allows to center the header
  legend8->AddEntry(tof1S[0],"Good Gap Events","f");
  legend8->AddEntry(tof1S[1],"P_{K_{#pi2}} cut","f");
  legend8->AddEntry(tof1S[2],"extra TOF1 #geq 2","f");
  legend8->AddEntry(tof1S[3],"P_{K_{#pi2}} and cos(#theta_{#pi^{+}#pi^{0}}) cut","f");
  legend8->Draw();

  TCanvas* c9 = new TCanvas("c9", " Testing Cooker: 1 ", 100, 100, 800, 650);
  c9->Divide(2,2);
  c9->cd(1);
  tof1IDvM[0]->SetTitle("TOF1 ID vs TOF1 score: All Gap Events");
  tof1IDvM[0]->GetXaxis()->SetTitle("TOF1 ID");
  tof1IDvM[0]->GetYaxis()->SetTitle("TOF1 score");
  tof1IDvM[0]->GetYaxis()->SetRange(0.0,8.);
  tof1IDvM[0]->GetXaxis()->SetTitleSize(0.045);
  tof1IDvM[0]->Draw("contz");

  c9->cd(2);
  tof1IDvM[1]->SetTitle("TOF1 ID vs TOF1 score: P_{K_{#pi2}} cut");
  tof1IDvM[1]->GetXaxis()->SetTitle("TOF1 ID");
  tof1IDvM[1]->GetYaxis()->SetTitle("TOF1 score");
  tof1IDvM[1]->GetYaxis()->SetRange(0.0,8.);
  tof1IDvM[1]->GetXaxis()->SetTitleSize(0.045);
  tof1IDvM[1]->Draw("contz");

  c9->cd(3);
  tof1IDvM[2]->SetTitle("TOF1 ID vs TOF1 score: extra TOF1 #geq 2");
  tof1IDvM[2]->GetXaxis()->SetTitle("TOF1 ID");
  tof1IDvM[2]->GetYaxis()->SetTitle("TOF1 score");
  tof1IDvM[2]->GetYaxis()->SetRange(0.0,8.);
  tof1IDvM[2]->GetXaxis()->SetTitleSize(0.045);
  tof1IDvM[2]->Draw("contz");

  c9->cd(4);
  tof1IDvM[3]->SetTitle("TOF1 ID vs TOF1 score: P_{K_{#pi2}} and cos(#theta_{#pi^{+}#pi^{0}}) cut");
  tof1IDvM[3]->GetXaxis()->SetTitle("TOF1 ID");
  tof1IDvM[3]->GetYaxis()->SetTitle("TOF1 score");
  tof1IDvM[3]->GetYaxis()->SetRange(0.0,8.);
  tof1IDvM[3]->GetXaxis()->SetTitleSize(0.045);
  tof1IDvM[3]->Draw("contz");

  TCanvas* c0 = new TCanvas("c0", " Testing Cooker: 1 ", 100, 100, 800, 650);
  c0->Divide(2,2);
  c0->cd(1);
  h1Eclust[3]->SetTitle("Total cluster energy");
  h1Eclust[3]->GetXaxis()->SetTitle("Energy_{#gamma#gamma} [GeV]");
  h1Eclust[3]->GetXaxis()->SetTitleSize(0.045);
  h1Eclust[3]->SetLineColor(kBlue);
  h1Eclust[3]->SetLineWidth(1);
  h1Eclust[3]->Draw("");

  c0->cd(2);
  h1Mass[3]->SetTitle("Invariant mass of 2#gamma");
  h1Mass[3]->GetXaxis()->SetTitle("M_{#gamma#gamma}");
  h1Mass[3]->GetXaxis()->SetTitleSize(0.045);
  h1Mass[3]->SetLineColor(kBlue);
  h1Mass[3]->SetLineWidth(1);
  h1Mass[3]->Draw("");

  c0->cd(3);
  angClust[3]->SetTitle("Opening angle of 2#gamma");
  angClust[3]->GetXaxis()->SetTitle("cos(#theta_{#gamma#gamma})");
  angClust[3]->GetXaxis()->SetTitleSize(0.045);
  angClust[3]->SetLineColor(kBlue);
  angClust[3]->SetLineWidth(1);
  angClust[3]->Draw("");

  c0->cd(4);
  h1piAng->SetTitle("Opening angle of #pi^{+}#pi^{0}");
  h1piAng->GetXaxis()->SetTitle("cos(#theta_{#pi^{+}#pi^{0}})");
  h1piAng->GetXaxis()->SetTitleSize(0.045);
  h1piAng->SetLineColor(kBlue);
  h1piAng->SetFillColor(kBeach);
  //h1piAng->SetFillStyle(3001);
  h1piAng->SetLineWidth(1);
  h1piAng->Draw("");
}
