using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Lab9
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "touristsDataSet.Info". При необходимости она может быть перемещена или удалена.
            this.infoTableAdapter.Fill(this.touristsDataSet.Info);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "touristsDataSet.Tourists". При необходимости она может быть перемещена или удалена.
            this.touristsTableAdapter.Fill(this.touristsDataSet.Tourists);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            touristsTableAdapter.Update(touristsDataSet);
            infoTableAdapter.Update(touristsDataSet);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            TouristsDataSet.TouristsRow newTouristsRow;
            newTouristsRow = touristsDataSet.Tourists.NewTouristsRow();
            newTouristsRow.id_Tourist = 3;
            newTouristsRow.Name = textBox2.Text;
            newTouristsRow.Surname = textBox3.Text;
            newTouristsRow.Address = textBox4.Text;
           /* newTouristsRow.Birthdate = Convert.ToDateTime(textBox5);*/
            this.touristsDataSet.Tourists.Rows.Add(newTouristsRow);
            this.touristsTableAdapter.Update(this.touristsDataSet.Tourists);
        }
        
        }
}
