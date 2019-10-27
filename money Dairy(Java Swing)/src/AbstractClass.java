import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableCellRenderer;
import java.awt.*;
import java.awt.event.ActionListener;

/**
 * Created by user on 12/26/2016.
 */
abstract public class AbstractClass{
    JFrame absFrame ;
    JLabel dateLb,categoryLb,amountLb,accountLb,memoLb;
    JComboBox dayJc,monthJc,yearJc,categoryJc,accountJc;
    JTextField amountTf;
    JTextArea memoTa;
    JButton addBt,updateBt,deleteBt;
    JTable jt;
    JPanel panel1,panelForButton;
    DefaultTableModel model;
    Object[] row = new Object[3];
    Container c;
    public AbstractClass() {
        absFrame = new JFrame();
        absFrame.setVisible(true);
       // absFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        absFrame.setResizable(false);
        absFrame.setBounds(100,0,700,700);
        c = absFrame.getContentPane();
        c.setLayout(null);

        // panel1 for date to memo;
        panel1 = new JPanel();
        panel1.setLayout(null);
    //  panel1.setBackground(Color.gray);
        panel1.setBounds(200,20,400,280);

        // JPanel for button;
        panelForButton = new JPanel(new FlowLayout(FlowLayout.CENTER,20,10));
    //    panelForButton.setBackground(Color.gray);
        panelForButton.setBounds(160,300,380,40);


        //add panel For table
        JPanel tableContainer = new JPanel();
        tableContainer.setBounds(50,380,600,300);
    //    tableContainer .setBackground(Color.lightGray);

        //code for create frame for Abstract class;
        dateLb = new JLabel("Date : ");
        categoryLb = new  JLabel("Category : ");
        amountLb = new JLabel("Amount : ");
        accountLb = new JLabel("Account : ");
        memoLb = new JLabel("Memo : ");
        //code for JLabel;
        dateLb.setBounds(10,30,60,20);
        categoryLb.setBounds(10,70,80,20);
        amountLb.setBounds(10,110,80,20);
        accountLb.setBounds(10,150,80,20);
        memoLb.setBounds(10,190,60,20);
        //setBounds for JLabel;
        String[] Day_arr = new String[31];
        for (int i = 1; i <= Day_arr.length; i++) {
            Day_arr[i - 1] = Integer.toString(i);
        }
        dayJc = new JComboBox(Day_arr);

        String[] month_arr = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        monthJc = new JComboBox(month_arr);
        String[] year_arr = new String[101];
        for (int i = 1950; i <= 2050; i++) {
            year_arr[i - 1950] = Integer.toString(i);
        }
        yearJc = new JComboBox(year_arr);
        //JComboBox for date;
        String category[] = {"","Salary","Tution fee","Business","Poket money"};
        categoryJc = new JComboBox(category);
        //JcomboBox for category;
        String account[] = {"","Bank","Cash","BKash","cheque"};
        accountJc = new JComboBox(account);
        //JComboBox for account;
        memoTa = new JTextArea();
        //memo field
        dayJc.setBounds(80,30,50,20);
        monthJc.setBounds(140,30,60,20);
        yearJc.setBounds(210,30,70,20);
        categoryJc.setBounds(80,70,100,20);
        accountJc.setBounds(80,150,100,20);
        memoTa.setBounds(80,190,200,50);
        //setBounds for JComboBox;
        amountTf = new JTextField();
        //JTextField for amount;
        amountTf.setBounds(80,110,100,20);
        //setBounds for amount;
        addBt = new JButton("Add");
        updateBt = new JButton("Update");
        deleteBt = new JButton("Delete");
        //code for JButton;
       /* addBt.setBounds(250,250,60,30);
        updateBt.setBounds(330,250,100,30);
        deleteBt.setBounds(450,250,100,30);*/
        //setBounds for JButton;

        //table frame
        jt = new JTable()
        {
            //for of editation of a table
            public boolean isCellEditable(int data, int columns){
                return false;
            }
            // for make different color one row to another row
            public Component prepareRenderer(TableCellRenderer r, int data, int column)
            {
                Component com = super.prepareRenderer(r,data,column);
                if(data % 2 ==0)
                    com.setBackground(Color.CYAN);
                else
                    com.setBackground(Color.PINK);
                //for if we click on any row change the color
                if(isCellSelected(data,column))
                    com.setBackground(Color.BLACK);

                return com;

            }
        };

        //table
        Object[] column = {"Date","Category","Amount","Account","Memo"}; //for column headeline
        model = new DefaultTableModel();
        model.setColumnIdentifiers(column);

        //set model
        jt.setModel(model);

        jt.setPreferredScrollableViewportSize(new Dimension(600,300)); // set table size
        jt.setFillsViewportHeight(true);

        JScrollPane jps = new JScrollPane(jt);
        jps.setBounds(0,0,600,300);



        c.add(panel1);
        panel1.add(dateLb);
        panel1.add(dayJc);
        panel1.add(monthJc);
        panel1.add(yearJc);
        panel1.add(categoryLb);
        panel1.add(amountLb);
        panel1.add(amountTf);
        panel1.add(accountLb);
        panel1.add(accountJc);
        panel1.add(memoLb);
        panel1.add(memoTa);
        c.add(panelForButton);
        panelForButton.add(addBt);
        panelForButton.add(updateBt);
        panelForButton.add(deleteBt);
        c.add(tableContainer);
        tableContainer.add(jps);

    }
}
