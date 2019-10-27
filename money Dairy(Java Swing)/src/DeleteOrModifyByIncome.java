import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * Created by Fakrul Uddin on 1/1/2017.
 */
public class DeleteOrModifyByIncome extends AbstractClass implements ActionListener,MouseListener {
    Object[] row = new Object[5];
    String filePath,brString,uName;
    TablePrintForDeleteOrModify printObj;
    static int i=-1;

    //constructor
    public DeleteOrModifyByIncome(String uName){
        filePath = uName;
        panel1.add(categoryJc);
        addBt.setVisible(false);
        this.uName=uName;
        addBt.addActionListener(this);
        updateBt.addActionListener(this);
        deleteBt.addActionListener(this);
        jt.addMouseListener(this);
        panel1.addMouseListener(this);
        dayJc.addActionListener(this);
        monthJc.addActionListener(this);
        yearJc.addActionListener(this);
        categoryJc.addActionListener(this);
        accountJc.addActionListener(this);
        printObj = new TablePrintForDeleteOrModify();
        printObj.printAll(this.model,(uName+"/income.txt"));
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(i < 0)
        {
            printObj = new TablePrintForDeleteOrModify();
            if (e.getSource() == dayJc) {
                String d = (String) dayJc.getSelectedItem();
                String row[] = new String[7];
                row[0] = d;
                row[1] = (String) monthJc.getSelectedItem();
                row[2] = (String) yearJc.getSelectedItem();
                row[3] = (String) categoryJc.getSelectedItem();
                row[4] = (String)amountTf.getText();
                row[5] = (String) accountJc.getSelectedItem();
                row[6] = (String)memoTa.getText();
                printObj.print1(model, row, (uName + "/income.txt"));

            }//enf of dayJC
            if (e.getSource() == monthJc) {
                JComboBox cb1 = (JComboBox) e.getSource();
                String m = (String) cb1.getSelectedItem();
                String row[] = new String[7];
                row[0] = (String) dayJc.getSelectedItem();
                row[1] = m;
                row[2] = (String) yearJc.getSelectedItem();
                row[3] = (String) categoryJc.getSelectedItem();
                row[4] = (String)amountTf.getText();
                row[5] = (String) accountJc.getSelectedItem();
                row[6] = (String)memoTa.getText();
                printObj.print2(model, row, (uName + "/income.txt"));
            }//enf of monthJC
            if (e.getSource() == yearJc) {
                JComboBox cb2 = (JComboBox) e.getSource();
                String y = (String) cb2.getSelectedItem();
                String row[] = new String[7];
                row[0] = (String) dayJc.getSelectedItem();
                row[1] = (String) monthJc.getSelectedItem();
                row[2] = y;
                row[3] = (String) categoryJc.getSelectedItem();
                row[4] = (String)amountTf.getText();
                row[5] = (String) accountJc.getSelectedItem();
                row[6] = (String)memoTa.getText();
                printObj.print3(model, row, (uName + "/income.txt"));
            }//enf of yearJC
            if (e.getSource() == categoryJc) {
                JComboBox cb3 = (JComboBox) e.getSource();
                String c = (String) cb3.getSelectedItem();
                String row[] = new String[7];
                row[0] = (String) dayJc.getSelectedItem();
                row[1] = (String) monthJc.getSelectedItem();
                row[2] = (String) yearJc.getSelectedItem();
                row[3] = c;
                row[4] = (String)amountTf.getText();
                row[5] = (String) accountJc.getSelectedItem();
                row[6] = (String)memoTa.getText();
                printObj = new TablePrintForDeleteOrModify();
                printObj.print4(model, row, (uName + "/income.txt"));
            }//enf of categoryJC
            /*if (e.getSource() == amountTf) {
                String am = (String) amountTf.getText();
                String row[] = new String[7];
                row[0] = (String) dayJc.getSelectedItem();
                row[1] = (String) monthJc.getSelectedItem();
                row[2] = (String) yearJc.getSelectedItem();
                row[3] = (String) categoryJc.getSelectedItem();
                row[4] = am;
                row[5] = (String) accountJc.getSelectedItem();
                row[6] = (String)memoTa.getText();
                printObj.print5(model, row, (uName + "/income.txt"));
            }//enf of amountJC*/
            if (e.getSource() == accountJc) {
                JComboBox cb4 = (JComboBox) e.getSource();
                String acc = (String) cb4.getSelectedItem();
                String row[] = new String[7];
                row[0] = (String) dayJc.getSelectedItem();
                row[1] = (String) monthJc.getSelectedItem();
                row[2] = (String) yearJc.getSelectedItem();
                row[3] = (String) categoryJc.getSelectedItem();
                row[4] = (String)amountTf.getText();
                row[5] = acc;
                row[6] = (String)memoTa.getText();
                printObj.print6(model, row, (uName + "/income.txt"));
            }//enf of accountJC
           /* if (e.getSource() == memoTf) {
                String mem = (String) amountTf.getText();
                String row[] = new String[7];
                row[0] = (String) dayJc.getSelectedItem();
                row[1] = (String) monthJc.getSelectedItem();
                row[2] = (String) yearJc.getSelectedItem();
                row[3] = (String) categoryJc.getSelectedItem();
                row[4] = (String)amountTf.getText();
                row[5] = (String) accountJc.getSelectedItem();
                row[6] = mem;
                printObj.print7(model, row, (uName + "/income.txt"));
            }//enf of memoTF*/
        }//enf of is seleceted row is null

        if(e.getSource()==deleteBt)
        {
            i = jt.getSelectedRow();
            if(i >= 0){
                List<String> temporaryFileArray = new ArrayList<String>(10);
                String deleteData = (model.getValueAt(i,0).toString())+"\t"+(model.getValueAt(i,1).toString())+"\t"+(model.getValueAt(i,2).toString())+"\t"+(model.getValueAt(i,3).toString())+"\t"+(model.getValueAt(i,4).toString());
                System.out.println("delete data: "+ deleteData);
                try {
                    BufferedReader br = new BufferedReader(new FileReader(filePath + "/income.txt"));
                    while((brString = br.readLine())!= null){
                        if(brString.equals(deleteData)){
                            continue;
                        }
                        else{
                            temporaryFileArray.add(brString);
                        }
                    }
                    br.close();
                    FileWriter fw = new FileWriter(filePath+"/income.txt");
                    BufferedWriter bw = new BufferedWriter(fw);
                    Iterator<String> it = temporaryFileArray.iterator();
                    while(it.hasNext()){
                        bw.write(it.next());
                        bw.write("\n");
                    }
                    bw.close();

                }catch (Exception eee)
                {
                    eee.getStackTrace();
                }
                // remove a row from jtable
                model.removeRow(i);
                //set null in textField
                amountTf.setText("");
                memoTa.setText("");
            }
            else{
                System.out.println("Delete Error");
            }
        }//end of delete button
        if(e.getSource()==updateBt)
        {
            i= jt.getSelectedRow();
            if(i >= 0 && !(amountTf.getText().isEmpty())){
                List<String> temporaryFileArray = new ArrayList<String>(10);
                String updateData = (model.getValueAt(i,0).toString())+"\t"+(model.getValueAt(i,1).toString())+"\t"+(model.getValueAt(i,2).toString())+"\t"+(model.getValueAt(i,3).toString())+"\t"+(model.getValueAt(i,4).toString());

                try {
                    BufferedReader br = new BufferedReader(new FileReader(filePath + "/income.txt"));
                    while((brString = br.readLine())!= null){
                        if(brString.equals(updateData)){
                            row[0] = dayJc.getSelectedItem();
                            row[1] = monthJc.getSelectedItem();
                            row[2] = yearJc.getSelectedItem();
                            row[0] = row[0] + "/" + row[1]+ "/" + row[2];
                            row[1] = categoryJc.getSelectedItem();
                            row[2] = amountTf.getText();
                            row[3] = accountJc.getSelectedItem();
                            row[4] = memoTa.getText();
                            String data= row[0] + "\t" + row[1] + "\t" + row[2] + "\t" + row[3] + "\t" + row[4];
                            //add update data to ArrayList
                            temporaryFileArray.add(data);
                        }
                        else{
                            temporaryFileArray.add(brString);
                        }
                    }
                    br.close();
                    FileWriter fw = new FileWriter(filePath+"/income.txt");
                    BufferedWriter bw = new BufferedWriter(fw);
                    Iterator<String> it = temporaryFileArray.iterator();
                    while(it.hasNext()){
                        bw.write(it.next());
                        bw.write("\n");
                    }
                    bw.close();

                }catch (Exception eee)
                {
                }
                // update the selected row of Jtable
                model.setValueAt(row[0], i, 0);
                model.setValueAt(row[1], i, 1);
                model.setValueAt(row[2], i, 2);
                model.setValueAt(row[3], i, 3);
                model.setValueAt(row[4], i, 4);
                //set null in textField
                amountTf.setText("");
                memoTa.setText("");
            }
            else{
                JOptionPane.showMessageDialog(null,"Fillup the amount field","messege",JOptionPane.ERROR_MESSAGE);
            }
        }//end of update button
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        // i = the index of the selected row
        if (e.getSource() == jt) {
            i = jt.getSelectedRow();
            amountTf.setText(model.getValueAt(i, 2).toString());
            memoTa.setText(model.getValueAt(i, 4).toString());
        }
        //is panel select
        if (e.getSource() == panel1) {
            int count = e.getClickCount();
            if (count == 1) {
                i=-1;
                //set null in textField
                amountTf.setText("");
                memoTa.setText("");

            }
        }
    }

    @Override
    public void mousePressed(MouseEvent e) {

    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }
}
