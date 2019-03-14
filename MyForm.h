#pragma once

#define d2 1
#define d1 -1
#define c 0.1
#define sbt 1
#define M 0.1
#define E 2.71

#include "Methods.h"

namespace YSALast {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int size = 4, size2 = 1;
	int counter = 0;
	float X = 0, Y = 0;
	float* position = new float[size];
	float* norm = new float[size];

	float* normalize = new float[size];
	double w[3] = { 1,1,1 };

	/// <summary>
	/// MyForm için özet
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Graphics ^ g;
	private: System::Windows::Forms::ToolStripMenuItem^  configurationnToolStripMenuItem;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	public:

	public:
		Pen ^ pen;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  processesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ýnitilazinToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deltaToolStripMenuItem;

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private:
		/// <summary>
		///Gerekli tasarýmcý deðiþkeni.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarýmcý desteði için gerekli metot - bu metodun 
		///içeriðini kod düzenleyici ile deðiþtirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->processesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ýnitilazinToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deltaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->configurationnToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->processesToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(547, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// processesToolStripMenuItem
			// 
			this->processesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ýnitilazinToolStripMenuItem,
					this->trainingToolStripMenuItem
			});
			this->processesToolStripMenuItem->Name = L"processesToolStripMenuItem";
			this->processesToolStripMenuItem->Size = System::Drawing::Size(70, 20);
			this->processesToolStripMenuItem->Text = L"Processes";
			// 
			// ýnitilazinToolStripMenuItem
			// 
			this->ýnitilazinToolStripMenuItem->Name = L"ýnitilazinToolStripMenuItem";
			this->ýnitilazinToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->ýnitilazinToolStripMenuItem->Text = L"Initialize";
			this->ýnitilazinToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ýnitilazinToolStripMenuItem_Click);
			// 
			// trainingToolStripMenuItem
			// 
			this->trainingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->deltaToolStripMenuItem,
					this->configurationnToolStripMenuItem
			});
			this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			this->trainingToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->trainingToolStripMenuItem->Text = L"Training";
			// 
			// deltaToolStripMenuItem
			// 
			this->deltaToolStripMenuItem->Name = L"deltaToolStripMenuItem";
			this->deltaToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->deltaToolStripMenuItem->Text = L"DeltaLearning";
			this->deltaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deltaToolStripMenuItem_Click);
			// 
			// configurationnToolStripMenuItem
			// 
			this->configurationnToolStripMenuItem->Name = L"configurationnToolStripMenuItem";
			this->configurationnToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->configurationnToolStripMenuItem->Text = L"Configurationn";
			this->configurationnToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::configurationnToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBox1->Location = System::Drawing::Point(28, 38);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(400, 300);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(440, 57);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(57, 17);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->Text = L"Class1";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(440, 93);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(57, 17);
			this->checkBox2->TabIndex = 3;
			this->checkBox2->Text = L"Class2";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(228, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(3, 300);
			this->label1->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(28, 188);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(400, 3);
			this->label2->TabIndex = 5;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(440, 160);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(89, 17);
			this->checkBox3->TabIndex = 6;
			this->checkBox3->Text = L"Normalization";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox3_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(547, 412);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		counter++;
		X = System::Convert::ToInt32(e->X);
		Y = System::Convert::ToInt32(e->Y);


		g = pictureBox1->CreateGraphics();
		Pen^ purple = gcnew Pen(Color::Purple, 2);
		Pen^ yellow = gcnew Pen(Color::Yellow, 2);

		if (checkBox1->Checked && checkBox2->Checked)
		{
			MessageBox::Show("Ýki class ayný anda seçilemez", "Uyarý");
		}

		else if (checkBox1->Checked)
		{
			int main_x = X - pictureBox1->Width / 2;
			int main_y = pictureBox1->Height / 2 - Y;
			position[size - 4] = main_x;
			position[size - 3] = main_y;
			position[size - 2] = sbt;
			position[size - 1] = d1;
			size += 4;

			g->DrawLine(purple, (X - 5), Y, (X + 5), Y);
			g->DrawLine(purple, X, (Y - 5), X, (Y + 5));

		}

		else if (checkBox2->Checked)
		{
			int main_x = X - pictureBox1->Width / 2;
			int main_y = pictureBox1->Height / 2 - Y;
			position[size - 4] = main_x;
			position[size - 3] = main_y;
			position[size - 2] = sbt;
			position[size - 1] = d2;
			size += 4;

			g->DrawLine(yellow, (X - 5), Y, (X + 5), Y);
			g->DrawLine(yellow, X, (Y - 5), X, (Y + 5));

		}
		else
		{
			MessageBox::Show("Bir class seçiniz.", "Uyarý!!!");
		}
	}
	private: System::Void ýnitilazinToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Random rnd;
		g = pictureBox1->CreateGraphics();
		Pen^ red = gcnew Pen(Color::Red, 2);

		for (int i = 0; i < 3; i++)
		{
			w[i] = rnd.NextDouble();
		}

		float* result = drawWeight(w, (float)pictureBox1->Width / 2, (float)(-(pictureBox1->Width / 2)));

		g->DrawLine(red, (float)0, pictureBox1->Height / 2 - result[1], (float)(pictureBox1->Width), (pictureBox1->Height / 2) - result[0]);
	}
	private: System::Void configurationnToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		int i = 0, j = 0, sgnNet = 0;
		float omegaKatsayi = 0;
		int error = 1;
		float net = 0;
		int k = 0;
		while (error > 0)
		{
			error = 0;
			i = 0;
			while (i < counter * 4)
			{
				k = 0;

				net = (w[k] * position[i]) + (w[k + 1] * position[i + 1]) + (w[k + 2] * position[i + 2]);

				if (net > 0)
					sgnNet = 1;
				else
					sgnNet = -1;

				omegaKatsayi = (c/2)* (position[i + 3] - sgnNet);


				w[k] += (omegaKatsayi * position[i]);
				w[k + 1] += omegaKatsayi * position[i + 1];
				w[k + 2] += omegaKatsayi * position[i + 2];


				error += Math::Abs(position[i + 3] - sgnNet) / 2;
				g = pictureBox1->CreateGraphics();
				pen = gcnew Pen(Color::Red, 2);
				float* result = drawWeight(w, (float)pictureBox1->Width / 2, (float)(-(pictureBox1->Width / 2)));
				pictureBox1->Refresh();

				if (checkBox3->Checked)
				{
					//Noktalarý picture boxda görüntülerken daha rahat görebilmek için x y noktlarýnýn bir katsayý ile çarpýlmasý
					for (int n = 0;n < counter * 4;n += 4)
					{
						norm[n] = position[n] * 15;
						norm[n + 1] = position[n + 1] * 15;
						norm[n + 2] = position[n + 2];
						norm[n + 3] = position[n + 3];
					}
				}
				//Normalizasyon gerçekleþtirilmemiþ ise
				else
				{
					//Noktalarda deðiþiklik yapmadan baþka bir diziye atýyorum
					for (int n = 0;n < counter * 4;n += 4)
					{
						norm[n] = position[n];
						norm[n + 1] = position[n + 1];
						norm[n + 2] = position[n + 2];
						norm[n + 3] = position[n + 3];

					}
				}

				for (int n = 0;n < counter * 4;n += 4)
				{
					//Hangi clasa aitse onun rengi seçiliyor
					if (norm[n + 3] == d1)
					{
						pen = gcnew Pen(Color::Purple, 2);
					}
					else if (norm[n + 3] == d2)
					{
						pen = gcnew Pen(Color::Yellow, 2);
					}

					//Kordinat düzlemine ait noktalar picturebox formatýna çeviriliyor
					X = (norm[n] + (pictureBox1->Width / 2));
					Y = ((pictureBox1->Height / 2) - (norm[n + 1]));

					//Noktalar ekrana çizdiriliyor
					g->DrawLine(pen, (X - 5), Y, (X + 5), Y);
					g->DrawLine(pen, X, (Y - 5), X, (Y + 5));

				}
				/////////////////////////////////////////
				//Normalizasyon yapmasý istenmezse bu kod parçasý kullanýlmalý

				/*for (int n = 0;n < counter * 4;n += 4)
				{
					if (position[n + 3] == d1)
					{
						pen = gcnew Pen(Color::Purple, 2);
					}
					else if (position[n + 3] == d2)
					{
						pen = gcnew Pen(Color::Yellow, 2);
					}

					X = position[n] + (pictureBox1->Width / 2);
					Y = (pictureBox1->Height / 2) - position[n + 1];

					g->DrawLine(pen, (X - 5), Y, (X + 5), Y);
					g->DrawLine(pen, X, (Y - 5), X, (Y + 5));
				}*/
				pen = gcnew Pen(Color::Blue, 2);
				g->DrawLine(pen, (float)0, pictureBox1->Height / 2 - result[1], (float)(pictureBox1->Width), (pictureBox1->Height / 2) - result[0]);

				i += 4;
			}

		}
	}
	private: System::Void deltaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		int i = 0, j = 0, sgnNet = 0;
		float omegaKatsayi = 0;
		double hata=0;
		float error = 2, eror=0;
		float net = 0, fNet = 0, türevfNet = 0;
		int k = 0;

		while (error>0.2)
		{
			//MessageBox::Show("  " + counter, "Uyarý");
			error = 0;
			i = 0;

			while (i < counter * 4)
			{
				k = 0;

				// 1 - net=w*x bulunmasý
				net = (w[k] * position[i]) + (w[k + 1] * position[i + 1]) + (w[k + 2] * position[i + 2]);

				// 2 - o=f(net) bulunmasý
				fNet = ((2 / (1 + Math::Pow(E, -net))) - 1);

				// 3 - Türev f(net)
				türevfNet = 0.5*(1 - ((0.5*fNet) * (0.5*fNet)));
				

				// 4 - omegaKatsayi=M*(d-o)*türevfNet
				omegaKatsayi =(float)( M * (position[i + 3] - fNet)*türevfNet);

				// 5 - W' = W + omegaKatsatisi * X

				w[k] += omegaKatsayi * position[i];
				w[k + 1] += omegaKatsayi * position[i + 1];
				w[k + 2] += omegaKatsayi * position[i + 2];

				//Error durumunun güncellenmesi
			    hata = (position[i + 3] - fNet);
				error += (Math::Pow(hata, 2) / (float)2);

				Graphics ^ g;
				g = pictureBox1->CreateGraphics();

				Pen ^ pen = gcnew Pen(Color::Red, 2);

				//Güncellenen aðýrlýk deðerlerinin (w) güncel doðruyu elde etmek için yeni güncel noktalarýn belirlenmesi
				float* degisken = drawWeight(w, (float)pictureBox1->Width / 2, (float)(-(pictureBox1->Width / 2)));

				//Refresh edilerek güncel verilerin picture boxda görüntülenmesi
				pictureBox1->Refresh();

				//Eðer normalizasyon iþlemi gerçekleþtirilmiþ ise
				if (checkBox3->Checked)
				{
				    //Noktalarý picture boxda görüntülerken daha rahat görebilmek için x y noktlarýnýn bir katsayý ile çarpýlmasý
					for (int n = 0;n < counter * 4;n += 4)
					{
						norm[n] = position[n] * 15;
						norm[n + 1] = position[n + 1] * 15;
						norm[n + 2] = position[n + 2];
						norm[n + 3] = position[n + 3];
					}
				}
				//Normalizasyon gerçekleþtirilmemiþ ise
				else
				{
					//Noktalarda deðiþiklik yapmadan baþka bir diziye atýyorum
					for (int n = 0;n < counter * 4;n += 4)
					{
						norm[n] = position[n] ;
						norm[n + 1] = position[n + 1] ;
						norm[n + 2] = position[n + 2];
						norm[n + 3] = position[n + 3];

					}
				}								
				
				for (int n = 0;n < counter * 4;n += 4)
				{
					//Hangi clasa aitse onun rengi seçiliyor
					if (norm[n + 3] == d1)
					{
						pen = gcnew Pen(Color::Purple, 2);
					}
					else if (norm[n + 3] == d2)
					{
						pen = gcnew Pen(Color::Yellow, 2);
					}									
					 
					//Kordinat düzlemine ait noktalar picturebox formatýna çeviriliyor
					X = (norm[n] + (pictureBox1->Width / 2));
					Y = ((pictureBox1->Height / 2) - (norm[n + 1]));

					//Noktalar ekrana çizdiriliyor
					g->DrawLine(pen, (X - 5), Y, (X + 5), Y);
					g->DrawLine(pen, X, (Y - 5), X, (Y + 5));
					
				}
				
				g = pictureBox1->CreateGraphics();
				Pen^ kalem = gcnew Pen(Color::Pink, 2);
				
				//Doðru güncellenen aðýrlýklar ile tekrar çizdiriliyor
				g->DrawLine(kalem, (float)0, pictureBox1->Height / 2 - (15*degisken[1]), (float)(pictureBox1->Width), (pictureBox1->Height / 2) - (15*degisken[0]));

				i += 4;
			}
			
		}
    }
    private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		float  varyansX=0, varyansY=0;
		float Xort = 0, Yort=0, ortX=0, ortY=0, ort=0, Xx=0, Yy=0;

		//Noktalarýn ortalama deðerlerini bulma
		for (int i = 0; i < counter * 4; i += 4)
		{
			ortX += position[i];			
			ortY += position[i+1];
		}
		Xort = ortX / counter;
		Yort = ortY / counter;

		//Varyans hesaplama
		for (int i = 0; i < counter * 4; i += 4)
		{
			Xx = (position[i] - Xort);
			ortX += Math::Pow(Xx,2);
			Yy = (position[i + 1] - Yort);
			ortY += Math::Pow(Yy, 2);
		}
		varyansX = Math::Sqrt(ortX / counter);
		varyansY = Math::Sqrt(ortY / counter);

		//Yeni noktalarý bulma
		for (int i = 0; i < counter * 4; i += 4)
		{

			position[i] =((position[i] - Xort) / varyansX);
			position[i + 1] = ((position[i+1] - Yort) / varyansY);
			position[i + 2] = position[i + 2];
			position[i + 3] = position[i + 3];
		}
    }
};
}