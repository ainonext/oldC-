using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Lab9_2
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
            newTouristsRow.id_Tourist = Convert.ToInt32(textBox1.Text);
            newTouristsRow.Name = textBox2.Text;
            newTouristsRow.Surname = textBox3.Text;
            newTouristsRow.Address = textBox4.Text;
            /*newTouristsRow.Birthdate = Convert.ToDateTime(textBox5);*/
            this.touristsDataSet.Tourists.Rows.Add(newTouristsRow);
            this.touristsTableAdapter.Update(this.touristsDataSet.Tourists);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            TouristsDataSet.TouristsRow oldTouristsRow;
            oldTouristsRow = touristsDataSet.Tourists.FindByid_Tourist(Convert.ToInt32(textBox1.Text));
            oldTouristsRow.Delete();
            this.touristsTableAdapter.Update(this.touristsDataSet.Tourists);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            /* string selectString =
        "Name Like '%" + textBox6.Text.Trim() + "%'";

             DataRowCollection allRows =
                 ((DataTable)dataGridView1.DataSource).Rows;

             DataRow[] searchedRows =
                 ((DataTable)dataGridView1.DataSource).
                     Select(selectString);

             int rowIndex = allRows.IndexOf(searchedRows[0]);

             dataGridView1.CurrentCell =
                 dataGridView1[0, rowIndex]; */
            for (int i = 0; i < dataGridView1.RowCount; i++)
                if (dataGridView1[1, i].FormattedValue.ToString().
                    Contains(textBox6.Text.Trim()))
                {
                    dataGridView1.CurrentCell = dataGridView1[0, i];
                    return;
                }

        }

        private void button5_Click(object sender, EventArgs e)
        {
           
            Application.Exit();
        }
    }
}
