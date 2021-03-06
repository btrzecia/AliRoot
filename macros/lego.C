#if !defined(__CINT__) || defined(__MAKECINT__)
#include <TROOT.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TH2F.h>
#endif

void lego() {
// macro to visualize the lego plots generated by gAlive->RunLego
   
   gROOT->Reset();
   TFile *file = new TFile("galice.root");

   Float_t theta = 10;
   Float_t phi   = 170;
   Int_t ncont   = 50;

   TCanvas *cgcm2 = new TCanvas("cgcm2","gcm2",200,100,600,400);
   cgcm2->SetTheta(theta);
   cgcm2->SetPhi(phi);
   TH2F *hgcm2 = (TH2F*)file->Get("hgcm2");
   hgcm2->SetFillColor(2);
   hgcm2->SetMaximum(1);
   hgcm2->SetContour(ncont);
   hgcm2->SetMaximum(50);
   hgcm2->Draw("lego2sphe");

   TCanvas *cabso = new TCanvas("cabso","abso",100,50,600,400);
   cabso->SetTheta(theta);
   cabso->SetPhi(phi);
   TH2F *habso = (TH2F*)file->Get("habso");
   habso->SetFillColor(2);
   habso->SetMaximum(1);
   habso->SetContour(ncont);
   habso->SetMaximum(1);
   habso->Draw("lego2sphe");

   TCanvas *cradl = new TCanvas("cradl","radl",10,10,600,400);
   cradl->SetTheta(theta);
   cradl->SetPhi(phi);
   TH2F *hradl = (TH2F*)file->Get("hradl");
   hradl->SetFillColor(2);
   hradl->SetMaximum(1);
   hradl->SetContour(ncont);
   hradl->SetMaximum(5);
   hradl->Draw("lego2sphe");
}   
