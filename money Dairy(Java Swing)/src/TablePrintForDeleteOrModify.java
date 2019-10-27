import javax.swing.table.DefaultTableModel;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

/**
 * Created by Fakrul Uddin on 1/1/2017.
 */
public class TablePrintForDeleteOrModify {
    public void printAll(DefaultTableModel model, String uname){
        try {
            //read for income text
            String line;
            BufferedReader br = new BufferedReader(new FileReader(uname));
            while ((line = br.readLine()) != null){
                String[] splitByTab =line.split("\t");
                model.addRow(splitByTab);
            }
            br.close();

        }catch(Exception e){
            e.getStackTrace();
        }
    }//end of print all in table
    public void print1(DefaultTableModel model, String[] row, String uname){

        //remove old view transaction from table if exist
        int rowCount = model.getRowCount();
        for(int i= rowCount-1; i>=0; i--)
        {
            model.removeRow(i);
        }

        try {
            //read for income text
            String line;
            BufferedReader br = new BufferedReader(new FileReader(uname));
            while ((line = br.readLine()) != null){
                String[] splitByTab =line.split("\t");
                String[] splitBySlash = splitByTab[0].split("/");
                if(splitBySlash[0].equals(row[0])){
                    model.addRow(splitByTab);
                }
            }
            br.close();

        }catch(Exception e){
            e.getStackTrace();
        }
    }
    public void print2(DefaultTableModel model, String[] row, String uname){

        //remove old view transaction from table if exist
        int rowCount = model.getRowCount();
        for(int i= rowCount-1; i>=0; i--)
        {
            model.removeRow(i);
        }
        try {
            //read for income text
            String line;
            BufferedReader br = new BufferedReader(new FileReader(uname));
            while ((line = br.readLine()) != null){
                String[] splitByTab = line.split("\t");
                String[] splitBySlash = splitByTab[0].split("/");
                if(splitBySlash[0].equals(row[0]) && splitBySlash[1].equals(row[1]) ){
                    model.addRow(splitByTab);
                }
            }
            br.close();

        }catch(Exception e){
            e.getStackTrace();
        }
    }

    public void print3(DefaultTableModel model, String[] row, String uname){

        //remove old view transaction from table if exist
        int rowCount = model.getRowCount();
        for(int i= rowCount-1; i>=0; i--)
        {
            model.removeRow(i);
        }

        try {
            //read for income text
            String line;
            BufferedReader br = new BufferedReader(new FileReader(uname));
            while ((line = br.readLine()) != null){
                String[] splitByTab = line.split("\t");
                String[] splitBySlash = splitByTab[0].split("/");
                if(splitBySlash[0].equals(row[0]) && splitBySlash[1].equals(row[1]) && splitBySlash[2].equals(row[2]) ){
                    model.addRow(splitByTab);
                }
            }
            br.close();

        }catch(Exception e){
            e.getStackTrace();
        }
    }
    public void print4(DefaultTableModel model, String[] row, String uname){

        //remove old view transaction from table if exist
        int rowCount = model.getRowCount();
        for(int i= rowCount-1; i>=0; i--)
        {
            model.removeRow(i);
        }

        try {
            //read for income text
            String line;
            BufferedReader br = new BufferedReader(new FileReader(uname));
            while ((line = br.readLine()) != null){
                String[] splitByTab = line.split("\t");
                String date = row[0] + "/" + row[1] + "/" + row[2];
                if(splitByTab[0].equals(date) && splitByTab[1].equals(row[3]) ){
                    model.addRow(splitByTab);
                }
            }
            br.close();

        }catch(Exception e){
            e.getStackTrace();
        }
    }
   /* public void print5(DefaultTableModel model, String[] row, String uname){

        //remove old view transaction from table if exist
        int rowCount = model.getRowCount();
        for(int i= rowCount-1; i>=0; i--)
        {
            model.removeRow(i);
        }

        try {
            //read for income text
            String line;
            BufferedReader br = new BufferedReader(new FileReader(uname));
            while ((line = br.readLine()) != null){
                String[] splitByTab = line.split("\t");
                String date = row[0] + "/" + row[1] + "/" + row[2];
                if(splitByTab[0].equals(date) && splitByTab[1].equals(row[3]) && splitByTab[2].equals(row[4]) ){
                    model.addRow(splitByTab);
                }
            }
            br.close();

        }catch(Exception e){
            e.getStackTrace();
        }
    }*/
    public void print6(DefaultTableModel model, String[] row, String uname){

        //remove old view transaction from table if exist
        int rowCount = model.getRowCount();
        for(int i= rowCount-1; i>=0; i--)
        {
            model.removeRow(i);
        }

        try {
            //read for income text
            String line;
            BufferedReader br = new BufferedReader(new FileReader(uname));
            while ((line = br.readLine()) != null){
                String[] splitByTab = line.split("\t");
                String date = row[0] + "/" + row[1] + "/" + row[2];
                if(splitByTab[0].equals(date) && splitByTab[1].equals(row[3]) && splitByTab[2].equals(row[4]) && splitByTab[3].equals(row[5]) ){
                    model.addRow(splitByTab);
                }
            }
            br.close();

        }catch(Exception e){
            e.getStackTrace();
        }
    }
   /* public void print7(DefaultTableModel model, String[] row, String uname){

        //remove old view transaction from table if exist
        int rowCount = model.getRowCount();
        for(int i= rowCount-1; i>=0; i--)
        {
            model.removeRow(i);
        }

        try {
            //read for income text
            String line;
            BufferedReader br = new BufferedReader(new FileReader(uname));
            while ((line = br.readLine()) != null){
                String[] splitByTab = line.split("\t");
                String date = row[0] + "/" + row[1] + "/" + row[2];
                if(splitByTab[0].equals(date) && splitByTab[1].equals(row[3]) && splitByTab[2].equals(row[4]) && splitByTab[3].equals(row[5]) && splitByTab[4].equals(row[6]) )
                {
                    model.addRow(splitByTab);
                }
            }
            br.close();

        }catch(Exception e){
            e.getStackTrace();
        }
    }*/

}
