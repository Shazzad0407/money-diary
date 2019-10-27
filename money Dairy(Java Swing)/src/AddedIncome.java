import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.*;
import java.util.Iterator;
import java.util.List;
import java.util.ArrayList;

public class AddedIncome extends AbstractClass implements ActionListener,MouseListener {
    Object[] row = new Object[5];
    String filePath,brString,uName;

    public AddedIncome(String uName){
        panel1.add(categoryJc);
        this.uName=uName;
        addBt.addActionListener(this);
        updateBt.addActionListener(this);
        deleteBt.addActionListener(this);
        jt.addMouseListener(this);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==addBt)
        {
            row[0] = dayJc.getSelectedItem();
            row[1] = monthJc.getSelectedItem();
            row[2] = yearJc.getSelectedItem();
            row[0] = row[0] + "/" + row[1]+ "/" + row[2];
            row[1] = categoryJc.getSelectedItem();
            row[2] = amountTf.getText();
            row[3] = accountJc.getSelectedItem();
            if(memoTa.getText().equals(""))
                row[4] = " ";
            else
                row[4] = memoTa.getText();
            // add row to the model
            if(!(amountTf.getText().isEmpty()))
            {
                model.addRow(row);
                //set null in textField
                amountTf.setText("");
                memoTa.setText("");
                //add data in File
                try{
                    filePath = uName;
                    File file = new File(filePath);
                    try {
                        //file.mkdirs();
                        if (!(file.exists())) {
                            file.mkdir();
                        }
                    }catch(Exception eee)
                    {
                    }
                    FileWriter fw = new FileWriter(filePath+"/income.txt", true);
                    BufferedWriter bw = new BufferedWriter(fw);
                    String data= row[0] + "\t" + row[1] + "\t" + row[2] + "\t" + row[3] + "\t" + row[4];
                    bw.write(data);
                    bw.write("\n");
                    bw.close();
                }catch(Exception eee){

                }
            }
            else {
                JOptionPane.showMessageDialog(null,"Fillup the amount field","messege",JOptionPane.ERROR_MESSAGE);
            }
        }//end of addBT
        if(e.getSource()==deleteBt)
        {
            int i= jt.getSelectedRow();
            if(i >= 0){
                List<String> temporaryFileArray = new ArrayList<String>(10);
                String deleteData = (model.getValueAt(i,0).toString())+"\t"+(model.getValueAt(i,1).toString())+"\t"+(model.getValueAt(i,2).toString())+"\t"+(model.getValueAt(i,3).toString())+"\t"+(model.getValueAt(i,4).toString());

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
            int i= jt.getSelectedRow();
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
                            if(memoTa.getText().equals(""))
                                row[4] = " ";
                            else
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
                JOptionPane.showMessageDialog(null,"Fillup the amount field","messege",JOptionPane.ERROR_MESSAGE);           }
        }//end of update button

    }

    @Override
    public void mouseClicked(MouseEvent e) {
        // i = the index of the selected row
        int i = jt.getSelectedRow();
        amountTf.setText(model.getValueAt(i, 2).toString());
        memoTa.setText(model.getValueAt(i, 4).toString());
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
