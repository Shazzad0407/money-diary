import javax.swing.table.DefaultTableModel;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by Fakrul Uddin on 12/31/2016.
 */
public class Sort {
    //conostructor
    public Sort(){}

    public void printData(DefaultTableModel model, List<String> Array){
        //remove old view transaction from table if exist
        int rowCount = model.getRowCount();
        for(int i= rowCount-1; i>=0; i--)
        {
            model.removeRow(i);
        }
        //print data in table
        for(String line : Array){
            String[] splitByTab = line.split("\t");
            model.addRow(splitByTab);
        }
    }
    //ascending by amount
    public List ascendingAmount(List<String> Array){
        int[] amount = new int[Array.size()];
        int i=0;
        for(String line : Array){
            String[] splitByTab = line.split("\t");
            amount[i] = Integer.parseInt(splitByTab[2]);
            i++;
        }
        Arrays.sort(amount);

        List<String> tempSortArr = new ArrayList<String>(10);
        for(i=0; i< Array.size(); i++ ){
            String data = Integer.toString(amount[i]);
            for(int j=0; j<Array.size(); j++){

                String[] splitByTab = Array.get(j).split("\t");

                if( data.equals(splitByTab[2]) /*&& !(Array.get(j).equals("i"))*/ ){
                    tempSortArr.add(Array.get(j));
                    System.out.println("a: " + tempSortArr);
                    //Array.set(j,"i");
                    break;
                }
            }
        }
        return tempSortArr;



    }

}
