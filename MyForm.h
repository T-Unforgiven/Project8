#pragma once
#include<cmath>
#include<cassert>
namespace Project8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			br = gcnew SolidBrush(Color::White);
			pn = gcnew Pen(Color::Black, 3);
			pb1->Image = gcnew Bitmap(pb1->Width, pb1->Height);
			Changes = gcnew array<float, 2>(3, 3);
			identity_mat(Changes);
			CurChanges = gcnew array<float, 2>(3, 3);
			identity_mat(CurChanges);
			PrevChanges = gcnew array<float, 2>(3, 3);
			identity_mat(PrevChanges);
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pb1;
	private: System::Windows::Forms::TextBox^ tbPointCounter;
	private: System::Windows::Forms::Button^ btnPlot;
	private: System::Windows::Forms::Button^ btnUp;
	private: System::Windows::Forms::Button^ btnDown;
	private: System::Windows::Forms::Button^ btnLeft;
	private: System::Windows::Forms::Button^ btnRight;
	private: System::Windows::Forms::ListBox^ lbPoints;
	private: System::Windows::Forms::Button^ btnRot1;
	private: System::Windows::Forms::Button^ btnRot2;
	private: System::Windows::Forms::Button^ btnScale1;
	private: System::Windows::Forms::Button^ btnScale2;
	private: System::Windows::Forms::Button^ btnScale3;
	private: System::Windows::Forms::Button^ btnScale4;




	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pb1 = (gcnew System::Windows::Forms::PictureBox());
			this->tbPointCounter = (gcnew System::Windows::Forms::TextBox());
			this->btnPlot = (gcnew System::Windows::Forms::Button());
			this->btnUp = (gcnew System::Windows::Forms::Button());
			this->btnDown = (gcnew System::Windows::Forms::Button());
			this->btnLeft = (gcnew System::Windows::Forms::Button());
			this->btnRight = (gcnew System::Windows::Forms::Button());
			this->lbPoints = (gcnew System::Windows::Forms::ListBox());
			this->btnRot1 = (gcnew System::Windows::Forms::Button());
			this->btnRot2 = (gcnew System::Windows::Forms::Button());
			this->btnScale1 = (gcnew System::Windows::Forms::Button());
			this->btnScale2 = (gcnew System::Windows::Forms::Button());
			this->btnScale3 = (gcnew System::Windows::Forms::Button());
			this->btnScale4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1))->BeginInit();
			this->SuspendLayout();
			// 
			// pb1
			// 
			this->pb1->Location = System::Drawing::Point(22, 22);
			this->pb1->Name = L"pb1";
			this->pb1->Size = System::Drawing::Size(656, 420);
			this->pb1->TabIndex = 0;
			this->pb1->TabStop = false;
			this->pb1->Click += gcnew System::EventHandler(this, &MyForm::pb1_Click);
			this->pb1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pb1_MouseClick);
			// 
			// tbPointCounter
			// 
			this->tbPointCounter->Location = System::Drawing::Point(1011, 106);
			this->tbPointCounter->Name = L"tbPointCounter";
			this->tbPointCounter->Size = System::Drawing::Size(134, 22);
			this->tbPointCounter->TabIndex = 1;
			this->tbPointCounter->Text = L"0";
			// 
			// btnPlot
			// 
			this->btnPlot->Location = System::Drawing::Point(750, 145);
			this->btnPlot->Name = L"btnPlot";
			this->btnPlot->Size = System::Drawing::Size(134, 44);
			this->btnPlot->TabIndex = 2;
			this->btnPlot->Text = L"Start_Ploting";
			this->btnPlot->UseVisualStyleBackColor = true;
			this->btnPlot->Click += gcnew System::EventHandler(this, &MyForm::btnPlot_Click);
			// 
			// btnUp
			// 
			this->btnUp->Location = System::Drawing::Point(750, 195);
			this->btnUp->Name = L"btnUp";
			this->btnUp->Size = System::Drawing::Size(134, 42);
			this->btnUp->TabIndex = 3;
			this->btnUp->Text = L"Move Up";
			this->btnUp->UseVisualStyleBackColor = true;
			this->btnUp->Click += gcnew System::EventHandler(this, &MyForm::btnUp_Click);
			// 
			// btnDown
			// 
			this->btnDown->Location = System::Drawing::Point(750, 243);
			this->btnDown->Name = L"btnDown";
			this->btnDown->Size = System::Drawing::Size(134, 46);
			this->btnDown->TabIndex = 4;
			this->btnDown->Text = L"Move Down";
			this->btnDown->UseVisualStyleBackColor = true;
			this->btnDown->Click += gcnew System::EventHandler(this, &MyForm::btnDown_Click);
			// 
			// btnLeft
			// 
			this->btnLeft->Location = System::Drawing::Point(750, 295);
			this->btnLeft->Name = L"btnLeft";
			this->btnLeft->Size = System::Drawing::Size(134, 45);
			this->btnLeft->TabIndex = 5;
			this->btnLeft->Text = L"Move Left";
			this->btnLeft->UseVisualStyleBackColor = true;
			this->btnLeft->Click += gcnew System::EventHandler(this, &MyForm::btnLeft_Click);
			// 
			// btnRight
			// 
			this->btnRight->Location = System::Drawing::Point(750, 346);
			this->btnRight->Name = L"btnRight";
			this->btnRight->Size = System::Drawing::Size(134, 44);
			this->btnRight->TabIndex = 6;
			this->btnRight->Text = L"Move Right";
			this->btnRight->UseVisualStyleBackColor = true;
			this->btnRight->Click += gcnew System::EventHandler(this, &MyForm::btnRight_Click);
			// 
			// lbPoints
			// 
			this->lbPoints->FormattingEnabled = true;
			this->lbPoints->ItemHeight = 16;
			this->lbPoints->Location = System::Drawing::Point(1011, 145);
			this->lbPoints->Name = L"lbPoints";
			this->lbPoints->Size = System::Drawing::Size(244, 132);
			this->lbPoints->TabIndex = 7;
			// 
			// btnRot1
			// 
			this->btnRot1->Location = System::Drawing::Point(750, 396);
			this->btnRot1->Name = L"btnRot1";
			this->btnRot1->Size = System::Drawing::Size(134, 45);
			this->btnRot1->TabIndex = 8;
			this->btnRot1->Text = L"Rotate clockwise";
			this->btnRot1->UseVisualStyleBackColor = true;
			this->btnRot1->Click += gcnew System::EventHandler(this, &MyForm::btnRot1_Click);
			// 
			// btnRot2
			// 
			this->btnRot2->Location = System::Drawing::Point(750, 447);
			this->btnRot2->Name = L"btnRot2";
			this->btnRot2->Size = System::Drawing::Size(134, 55);
			this->btnRot2->TabIndex = 9;
			this->btnRot2->Text = L"Rotate counterclockwise";
			this->btnRot2->UseVisualStyleBackColor = true;
			this->btnRot2->Click += gcnew System::EventHandler(this, &MyForm::btnRot2_Click);
			// 
			// btnScale1
			// 
			this->btnScale1->Location = System::Drawing::Point(1030, 295);
			this->btnScale1->Name = L"btnScale1";
			this->btnScale1->Size = System::Drawing::Size(134, 45);
			this->btnScale1->TabIndex = 10;
			this->btnScale1->Text = L"H: scale+";
			this->btnScale1->UseVisualStyleBackColor = true;
			this->btnScale1->Click += gcnew System::EventHandler(this, &MyForm::btnScale1_Click);
			// 
			// btnScale2
			// 
			this->btnScale2->Location = System::Drawing::Point(1030, 346);
			this->btnScale2->Name = L"btnScale2";
			this->btnScale2->Size = System::Drawing::Size(134, 44);
			this->btnScale2->TabIndex = 11;
			this->btnScale2->Text = L"H: scale-";
			this->btnScale2->UseVisualStyleBackColor = true;
			this->btnScale2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// btnScale3
			// 
			this->btnScale3->Location = System::Drawing::Point(1030, 399);
			this->btnScale3->Name = L"btnScale3";
			this->btnScale3->Size = System::Drawing::Size(134, 43);
			this->btnScale3->TabIndex = 12;
			this->btnScale3->Text = L"V: scale+";
			this->btnScale3->UseVisualStyleBackColor = true;
			this->btnScale3->Click += gcnew System::EventHandler(this, &MyForm::btnScale3_Click);
			// 
			// btnScale4
			// 
			this->btnScale4->Location = System::Drawing::Point(1030, 448);
			this->btnScale4->Name = L"btnScale4";
			this->btnScale4->Size = System::Drawing::Size(134, 41);
			this->btnScale4->TabIndex = 13;
			this->btnScale4->Text = L"V: scale-";
			this->btnScale4->UseVisualStyleBackColor = true;
			this->btnScale4->Click += gcnew System::EventHandler(this, &MyForm::btnScale4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1267, 628);
			this->Controls->Add(this->btnScale4);
			this->Controls->Add(this->btnScale3);
			this->Controls->Add(this->btnScale2);
			this->Controls->Add(this->btnScale1);
			this->Controls->Add(this->btnRot2);
			this->Controls->Add(this->btnRot1);
			this->Controls->Add(this->lbPoints);
			this->Controls->Add(this->btnRight);
			this->Controls->Add(this->btnLeft);
			this->Controls->Add(this->btnDown);
			this->Controls->Add(this->btnUp);
			this->Controls->Add(this->btnPlot);
			this->Controls->Add(this->tbPointCounter);
			this->Controls->Add(this->pb1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		int iterator = 0;
		int  PointCounter;
		array<PointF>^ Points;
		array<PointF>^ Points1;
		Brush^ br;
		Pen^ pn;
		array<float, 2>^ Changes;
		array<float, 2>^ CurChanges;
		array<float, 2>^ PrevChanges;
		bool start = true;
		int Last;

	Point initialMousePos;

	//перемножение матриц
	void multiply(array<float, 2>^ A, array<float, 2>^ B, array<float, 2>^ C) {
		int n = A->GetLength(0), m = B->GetLength(1), k = A->GetLength(1);
		assert(k == B->GetLength(0) && n == C->GetLength(0) && m == C->GetLength(1));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				C[i, j] = 0;
				for (int p = 0; p < k; p++)
					C[i, j] += A[i, p] * B[p, j];
			}
	}
	//единична€ матрица
	void identity_mat(array<float, 2>^ M) {
		int n = M->GetLength(0), m = M->GetLength(1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				M[i, j] = float(i == j);
	}
	//функци€ сдвига
	void move_mat(float dx, float dy, array<float, 2>^ T) {
		identity_mat(T);
		T[0, T->GetLength(1) - 1] = dx;
		T[1, T->GetLength(1) - 1] = dy;
	}
	//функци€ масштабировани€
	void scale_mat(float kx, float ky, array<float, 2>^ S) {
		identity_mat(S);
		S[0, 0] = kx;
		S[1, 1] = ky;
	}
	//функци€ поворота
	void rotate_mat(float phi, array<float, 2>^ R) {
		identity_mat(R);
		R[0, 0] = cos(phi);
		R[1, 1] = cos(phi);
		R[0, 1] = sin(phi);
		R[1, 0] = -R[0, 1];
	}

	PointF apply(PointF p, array<float, 2>^ M) {//что она делает, зачем нужна?
		return PointF(p.X * M[0, 0] + p.Y * M[0, 1] + M[0, 2], p.X * M[1, 0] + p.Y * M[1, 1] + M[1, 2]);
	}

	void scale_mat(PointF c, float kx, float ky, array<float, 2>^ S) {
		scale_mat(kx, ky, S);
		PointF scaled_c = apply(c, S);
		S[0, S->GetLength(1) - 1] = c.X - scaled_c.X;
		S[1, S->GetLength(1) - 1] = c.Y - scaled_c.Y;
	}

	void rotate_mat(PointF c, float phi, array<float, 2>^ R) {
		rotate_mat(phi, R);
		PointF rot_c = apply(c, R);
		R[0, R->GetLength(1) - 1] = c.X - rot_c.X;
		R[1, R->GetLength(1) - 1] = c.Y - rot_c.Y;
	}


	void clear(Image^ img, Brush^ b) {
		Graphics^ gr = Graphics::FromImage(img);
		gr->FillRectangle(b, 0, 0, img->Width, img->Height);
	}

	void replot() {
		clear(pb1->Image, br);
		Graphics^ gr = Graphics::FromImage(pb1->Image);
		gr->DrawPolygon(pn, Points1);
		pb1->Refresh();
	}

	void uploadchanges() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				PrevChanges[i, j] = Changes[i, j];
			}
		}
	}

	void uploadlb() {
		lbPoints->Items->Clear();
		for (int i = 0; i < iterator; i++) {
			lbPoints->Items->Add(Points1[i]);
		}
		lbPoints->Items->Add("0; 0");
	}

	void NEW() {
		multiply(CurChanges, PrevChanges, Changes);
		for (int i = 0; i < Points->Length; i++) {
			Points1[i] = apply(Points[i], Changes);
		}
		replot();
		uploadchanges();
		uploadlb();
	}

	private: System::Void pb1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void pb1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (iterator < PointCounter) {
			initialMousePos = e->Location;
			Points[iterator++] = initialMousePos;
			lbPoints->Items->Add(initialMousePos);
			if (iterator == PointCounter) {
				clear(pb1->Image, br);
				Graphics^ gr = Graphics::FromImage(pb1->Image);
				gr->DrawPolygon(pn, Points);
				pb1->Refresh();
				lbPoints->Items->Add("0; 0");
				for (int i = 0; i < iterator; i++) {
					Points1[i] = Points[i];
				}
			}
		}
	}
	private: System::Void btnPlot_Click(System::Object^ sender, System::EventArgs^ e) {
		if (start) {
			PointCounter = System::Convert::ToDouble(tbPointCounter->Text);
			Points = gcnew array<PointF>(PointCounter);
			Points1 = gcnew array<PointF>(PointCounter);
			start = false;
			Last = PointCounter;
		}
	}
	private: System::Void btnUp_Click(System::Object^ sender, System::EventArgs^ e) {
		move_mat(0, -10, CurChanges);
		NEW();
	}
private: System::Void btnDown_Click(System::Object^ sender, System::EventArgs^ e) {
	move_mat(0, 10, CurChanges);
	NEW();
}
private: System::Void btnLeft_Click(System::Object^ sender, System::EventArgs^ e) {
	move_mat(-10, 0, CurChanges);
	NEW();
}
private: System::Void btnRight_Click(System::Object^ sender, System::EventArgs^ e) {
	move_mat(10, 0, CurChanges);
	NEW();
}
private: System::Void btnRot1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (lbPoints->SelectedIndex > -1) {
		int index = lbPoints->SelectedIndex;
		if (index == iterator) {
			rotate_mat(-0.52, CurChanges);
		}
		else {
			rotate_mat(Points1[index], -0.52, CurChanges);
		}
		Last = lbPoints->SelectedIndex;
		NEW();
		lbPoints->SelectedIndex = Last;
	}
}
private: System::Void btnRot2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (lbPoints->SelectedIndex > -1) {
		int index = lbPoints->SelectedIndex;
		if (index == iterator) {
			rotate_mat(0.52, CurChanges);
		}
		else {
			rotate_mat(Points1[index], 0.52, CurChanges);
		}
		Last = lbPoints->SelectedIndex;
		NEW();
		lbPoints->SelectedIndex = Last;
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (lbPoints->SelectedIndex > -1) {
		int index = lbPoints->SelectedIndex;
		if (index == iterator) {
			scale_mat(0.5, 1, CurChanges);
		}
		else {
			scale_mat(Points1[index], 0.5, 1, CurChanges);
		}
		Last = lbPoints->SelectedIndex;
		NEW();
		lbPoints->SelectedIndex = Last;
	}
}
private: System::Void btnScale1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (lbPoints->SelectedIndex > -1) {
		int index = lbPoints->SelectedIndex;
		if (index == iterator) {
			scale_mat(2, 1, CurChanges);
		}
		else {
			scale_mat(Points1[index], 2, 1, CurChanges);
		}
		Last = lbPoints->SelectedIndex;
		NEW();
		lbPoints->SelectedIndex = Last;
	}
}
private: System::Void btnScale3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (lbPoints->SelectedIndex > -1) {
		int index = lbPoints->SelectedIndex;
		if (index == iterator) {
			scale_mat(1, 2, CurChanges);
		}
		else {
			scale_mat(Points1[index], 1, 2, CurChanges);
		}
		Last = lbPoints->SelectedIndex;
		NEW();
		lbPoints->SelectedIndex = Last;
	}
}
private: System::Void btnScale4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (lbPoints->SelectedIndex > -1) {
		int index = lbPoints->SelectedIndex;
		if (index == iterator) {
			scale_mat(1, 0.5, CurChanges);
		}
		else {
			scale_mat(Points1[index], 1, 0.5, CurChanges);
		}
		Last = lbPoints->SelectedIndex;
		NEW();
		lbPoints->SelectedIndex = Last;
	}
}
};
}
