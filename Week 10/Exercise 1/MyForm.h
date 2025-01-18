#pragma once
#include "CVecFigura.h"

namespace algoritmossem10jueves {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		CVecFigura* objVecFigura;
		Graphics^ g;
		BufferedGraphics^ buffer;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
		   /// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(758, 579);
			this->Name = L"MyForm";
			this->Text = L"Figuras";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		objVecFigura = new CVecFigura();
		g = this->CreateGraphics();
		BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
		buffer = context->Allocate(g, this->ClientRectangle);
		delete context;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(this->BackColor);
		objVecFigura->dibujar(buffer->Graphics);
		objVecFigura->mover(this->ClientRectangle.Width, this->ClientRectangle.Height);
		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		int tipo = 0;
		//	1 Rectangulo
		// 2 Circulo
		// 3 Triangulo
		if (e->KeyCode == Keys::R) tipo = 1;
		if (e->KeyCode == Keys::C) tipo = 2;
		if (e->KeyCode == Keys::T) tipo = 3;
		if (e->KeyCode == Keys::Escape) this->Close();
		if (tipo != 0) objVecFigura->agregar(tipo);
	}
	};
}
