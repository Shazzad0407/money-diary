import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableCellRenderer;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.*;
import java.util.List;
import java.util.ArrayList;

abstract public class ViewTransection implements ActionListener{
    JTable jt,jt1;
    DefaultTableModel model,model1;
    JPanel incomeTablePanel,costTablePanel;
    public JLabel sortByLb,totalBalanceLb,incomeStatementLb,sortByLb1,totalBalanceLb1,costStatementLb;
    JComboBox sortJc,sortJc1;
    JButton showInGraphJb,printJb,showInGraphJb1,printJb1;
    List<String> incomeArray;
    List<String> costArray;
    Sort sortView;
    Font font;
    //public variable
    public String incomeLable= "income of current month ";
 //   Object[] row = new Object[5];
    //constructor
    public ViewTransection(){}

    public void viewTransection(JPanel f, DefaultTableModel model, DefaultTableModel model1 ){
        //Container c= f.getContentPane();
        this.model = model;
        this.model1 = model1;
        //incomeTable container
        incomeTablePanel = new JPanel(null);
       // incomeTablePanel.setBackground(Color.lightGray);


        sortByLb = new JLabel("Sort By :");


        totalBalanceLb = new JLabel("Total Balance : ");

        incomeStatementLb = new JLabel(incomeLable);

        String [] sort_arr = {"","Ascending by date","Descending by date","Ascending by amount","Descending by amount"};
        sortJc = new JComboBox(sort_arr);
        //sortJc.setBounds(70,2,130,20);
        //sortJc.addActionListener(this);

        showInGraphJb = new JButton("Show Graph ");
        showInGraphJb.setBounds(300,230,100,20);

        printJb = new JButton("Print ");
        printJb.setBounds(425,230,100,20);
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
        //model = new DefaultTableModel();
        model.setColumnIdentifiers(column);

        //set model
        jt.setModel(model);

        jt.setPreferredScrollableViewportSize(new Dimension(900,200)); // set table size
        jt.setFillsViewportHeight(true);

        JScrollPane jps = new JScrollPane(jt);
        jps.setBounds(0,10,900,200);

        f.add(incomeTablePanel);
        incomeTablePanel.add(jps);
       // incomeTablePanel.add(sortByLb);
       // incomeTablePanel.add(sortJc);
       // incomeTablePanel.add(incomeStatementLb);
      //  incomeTablePanel.add(totalBalanceLb);
        f.add(totalBalanceLb);

        incomeTablePanel.add(showInGraphJb);
        incomeTablePanel.add(printJb);

        incomeTablePanel.setBounds(150,20,900,250);
        incomeTablePanel.setVisible(true);

        //costTable container
        costTablePanel = new JPanel(null);
       // costTablePanel.setBackground(Color.lightGray);

        sortByLb1 = new JLabel("Sort By :");
        sortByLb1.setBounds(15,5,50,15);

        totalBalanceLb1 = new JLabel("Total Balance : ");
        totalBalanceLb1.setBounds(720,0,300,15);

        costStatementLb = new JLabel(incomeLable);
        costStatementLb.setBounds(330,0,200,20);

        String [] sort_arr1 = {"","Ascending by date ","Descending by date ","Ascending by amount ","Descending by amount "};
        sortJc1 = new JComboBox(sort_arr1);
        sortJc1.setBounds(70,2,130,20);
        sortJc1.addActionListener(this);

        showInGraphJb1 = new JButton("Show Graph ");
        showInGraphJb1.setBounds(300,230,100,20);

        printJb1 = new JButton("Print ");
        printJb1.setBounds(425,230,100,20);
        //table frame
        jt1 = new JTable()
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
        //model1 = new DefaultTableModel();
        model1.setColumnIdentifiers(column);
        //set model
        jt1.setModel(model1);
        jt1.setPreferredScrollableViewportSize(new Dimension(900,200)); // set table size
        jt1.setFillsViewportHeight(true);

        JScrollPane jps1 = new JScrollPane(jt1);
        jps1.setBounds(0,0,900,200);
        f.add(costTablePanel);
        costTablePanel.add(jps1);
        //costTablePanel.add(sortByLb1);
        //costTablePanel.add(sortJc1);
        //costTablePanel.add(costStatementLb);
      //  costTablePanel.add(totalBalanceLb1);
        costTablePanel.add(showInGraphJb1);
        costTablePanel.add(printJb1);

        costTablePanel.setBounds(150,380,900,300);
        costTablePanel.setBackground(Color.CYAN);
        costTablePanel.setVisible(true);
    }
    //for current month transection
    public void currentMonthTransection(String uName, JPanel f){

        //get the current month
        Calendar cal = Calendar.getInstance();
        int m = cal.get(Calendar.MONTH)+ 1;
        int y = cal.get(Calendar.YEAR);
        // make the month and year in string
        String year,month,month1;
        if(m==1) {
            month = "Jan";
            month1 = "January";
        }
        else if(m==2) {
            month = "Feb";
            month1 = "February";
        }
        else if(m==3){
            month = "Mar";
            month1 = "March";
        }
        else if(m==4) {
            month = "Apr";
            month1 = "April";
        }
        else if(m==5){
            month = "May";
            month1 = "May";
        }
        else if(m==6){
            month = "Jun";
            month1 = "June";
        }
        else if(m==7){
            month = "Jul";
            month1 = "July";
        }
        else if(m==8){
            month = "Aug";
            month1 = "Augest";
        }
        else if(m==9){
            month = "Sep";
            month1 = "September";
        }
        else if(m==10){
            month = "Oct";
            month1 = "October";
        }
        else if(m==11){
            month = "Nov";
            month1 = "November";
        }
        else{
            month = "Dec";
            month1 = "December";
        }
        //change the heading
        incomeStatementLb.setText("Income Statement Of "+ month1 + " " + y);
        incomeStatementLb.setBounds(450,0,350,18);
        f.add(incomeStatementLb);
        font = new Font("Arial",Font.BOLD,18);
        incomeStatementLb.setFont(font);
        incomeStatementLb.setVisible(true);

        sortByLb.setBounds(150,0,50,15);
        f.add(sortByLb);
        sortJc.setBounds(200,0,130,20);
        f.add(sortJc);
        sortJc.addActionListener(this);

        costStatementLb.setText("Cost Statement Of "+ month1 + " " + y);
        costStatementLb.setBounds(450,350,350,18);
        f.add(costStatementLb);
        font = new Font("Arial",Font.BOLD,18);
        costStatementLb.setFont(font);
        costStatementLb.setVisible(true);

        sortByLb1.setBounds(150,350,50,15);
        f.add(sortByLb1);
        sortJc1.setBounds(200,350,130,20);
        f.add(sortJc1);
        sortJc1.addActionListener(this);



        //read only current month statement from file
        try {
            String line;
            int balance =0;
            //read for income text
            BufferedReader br = new BufferedReader(new FileReader(uName + "/income.txt"));
            incomeArray = new ArrayList<String>(10);
            while ((line = br.readLine()) != null){
                String[] splitByTab = line.split("\t");
                    String[] splitBySlash = splitByTab[0].split("/");
                    year = Integer.toString(y);
                    if(splitBySlash[1].equals(month) && splitBySlash[2].equals(year)){
                        balance+=Integer.parseInt(splitByTab[2]);
                        //for sorting purpose
                        incomeArray.add(line);
                }
            }
            sortView = new Sort();
            sortView.printData(model,incomeArray);
            br.close();
            //change the balance lebel
            totalBalanceLb.setText("Total Balance : "+ balance +" tk");
            totalBalanceLb.setBounds(900,00,300,15);
            f.add(totalBalanceLb);
            totalBalanceLb.setVisible(true);

            //red for cost text
            br = new BufferedReader(new FileReader(uName + "/cost.txt"));
            costArray = new ArrayList<String>(10);
            balance=0;
            while ((line = br.readLine()) != null){
                String[] splitByTab = line.split("\t");
                String[] splitBySlash = splitByTab[0].split("/");
                year= Integer.toString(y);
                if(splitBySlash[1].equals(month) && splitBySlash[2].equals(year)){
                    model1.addRow(splitByTab);
                    balance+=Integer.parseInt(splitByTab[2]);
                    //for sorting purpose
                    costArray.add(line);
                }
            }
            sortView.printData(model,incomeArray);
            br.close();
            //change the balance lebel
            totalBalanceLb1.setText("Total Balance : "+ balance +" tk");
            totalBalanceLb1.setBounds(900,360,300,15);
            f.add(totalBalanceLb1);
            totalBalanceLb1.setVisible(true);
        }catch(Exception e){
            e.getStackTrace();
        }

    }
    public void viewAllTansaction(String uName, JPanel f){
        incomeStatementLb.setText("Income Statement Of All Transaction");
        incomeStatementLb.setBounds(450,0,350,18);
        f.add(incomeStatementLb);
        font = new Font("Arial",Font.BOLD,18);
        incomeStatementLb.setFont(font);
        incomeStatementLb.setVisible(true);

        costStatementLb.setText("Cost Statement Of All Transaction");
        costStatementLb.setBounds(450,350,350,18);
        f.add(costStatementLb);
        font = new Font("Arial",Font.BOLD,18);
        costStatementLb.setFont(font);
        costStatementLb.setVisible(true);

        sortByLb1.setBounds(150,350,50,15);
        f.add(sortByLb1);
        sortJc1.setBounds(200,350,130,20);
        f.add(sortJc1);
        sortJc1.addActionListener(this);

        sortByLb.setBounds(150,0,50,15);
        f.add(sortByLb);
        sortJc.setBounds(200,0,130,20);
        f.add(sortJc);
        sortJc.addActionListener(this);
        try {
            String line;
            int balance =0;
            //read for income text
            BufferedReader br = new BufferedReader(new FileReader(uName + "/income.txt"));
            incomeArray = new ArrayList<String>(10);
            while ((line = br.readLine()) != null){
                String[] splitByTab = line.split("\t");
                balance = balance+Integer.parseInt(splitByTab[2]);
                    //for sorting purpose
                    incomeArray.add(line);
                }
            sortView = new Sort();
            sortView.printData(model,incomeArray);
            br.close();
            //change the balance lebel
            totalBalanceLb.setText("Total Balance : "+ balance +" tk");
            totalBalanceLb.setBounds(900,00,300,15);
            f.add(totalBalanceLb);
            totalBalanceLb.setVisible(true);
            //red for cost text
            br = new BufferedReader(new FileReader(uName + "/cost.txt"));
            costArray = new ArrayList<String>(10);
            balance=0;
            while ((line = br.readLine()) != null){
                String[] splitByTab = line.split("\t");
                balance = balance+Integer.parseInt(splitByTab[2]);
                costArray.add(line);
                }
            sortView.printData(model1,costArray);
            br.close();
            //change the balance lebel;
            totalBalanceLb1.setText("Total Balance : "+ balance +" tk");
            totalBalanceLb1.setBounds(900,360,300,15);
            f.add(totalBalanceLb1);
            totalBalanceLb1.setVisible(true);
        }catch(Exception ee){
            ee.getStackTrace();
        }
    }
    public void viewSpecificYearTransaction(String uName,String uYear,JPanel f){
        incomeStatementLb.setText("Income Statement Of "+""+uYear);
        incomeStatementLb.setBounds(450,0,350,18);
        f.add(incomeStatementLb);
        font = new Font("Arial",Font.BOLD,18);
        incomeStatementLb.setFont(font);
        incomeStatementLb.setVisible(true);


        sortByLb.setBounds(150,0,50,15);
        f.add(sortByLb);
        sortJc.setBounds(200,0,130,20);
        f.add(sortJc);
        sortJc.addActionListener(this);
        costStatementLb.setText("Cost Statement Of "+uYear);
        costStatementLb.setBounds(450,350,350,18);
        f.add(costStatementLb);
        font = new Font("Arial",Font.BOLD,18);
        costStatementLb.setFont(font);
        costStatementLb.setVisible(true);

        sortByLb1.setBounds(150,350,50,15);
        f.add(sortByLb1);
        sortJc1.setBounds(200,350,130,20);
        f.add(sortJc1);
        sortJc1.addActionListener(this);
        try {
            String line;
            int balance = 0;
            //read for income text
            BufferedReader br = new BufferedReader(new FileReader(uName + "/income.txt"));
            incomeArray = new ArrayList<String>(10);
            while ((line = br.readLine()) != null) {
                String[] splitByTab = line.split("\t");
                String[] splitBySlash = splitByTab[0].split("/");
             //  String  year = uYear;//Integer.toString(uYear);
                if (splitBySlash[2].equals(uYear)) {
                    balance += Integer.parseInt(splitByTab[2]);
                    //for sorting purpose
                    incomeArray.add(line);
                }
            }
            sortView = new Sort();
            sortView.printData(model,incomeArray);
            br.close();
            //change the balance lebel
            totalBalanceLb.setText("Total Balance : "+ balance +" tk");
            totalBalanceLb.setBounds(900,00,300,15);
            f.add(totalBalanceLb);
            totalBalanceLb.setVisible(true);
            //red for cost text
            br = new BufferedReader(new FileReader(uName + "/cost.txt"));
            costArray = new ArrayList<String>(10);
            balance=0;
            while ((line = br.readLine()) != null){
                String[] splitByTab = line.split("\t");
                String[] splitBySlash = splitByTab[0].split("/");

                if (splitBySlash[2].equals(uYear)) {
                    balance += Integer.parseInt(splitByTab[2]);
                    //for sorting purpose
                    costArray.add(line);
                }
            }
            sortView.printData(model1,costArray);
            br.close();
            //change the balance lebel;
            totalBalanceLb1.setText("Total Balance : "+ balance +" tk");
            totalBalanceLb1.setBounds(900,360,300,15);
            f.add(totalBalanceLb1);
            totalBalanceLb1.setVisible(true);
        }catch(Exception ee){
            ee.getStackTrace();
        }
    }
    public void viewSpecificMonthTransaction(String uName,String uMonth,String uYear,JPanel f){
            //change the heading
            incomeStatementLb.setText("Income Statement Of "+""+ uMonth+" "+uYear);
            incomeStatementLb.setBounds(450,0,350,18);
            f.add(incomeStatementLb);
            font = new Font("Arial",Font.BOLD,18);
            incomeStatementLb.setFont(font);
            incomeStatementLb.setVisible(true);

            sortByLb.setBounds(150,0,50,15);
            f.add(sortByLb);
            sortJc.setBounds(200,0,130,20);
            f.add(sortJc);
            sortJc.addActionListener(this);
            costStatementLb.setText("Cost Statement Of "+""+ uMonth+" "+uName);
            costStatementLb.setBounds(450,350,350,18);
            f.add(costStatementLb);
            font = new Font("Arial",Font.BOLD,18);
            costStatementLb.setFont(font);
            costStatementLb.setVisible(true);

            sortByLb1.setBounds(150,350,50,15);
            f.add(sortByLb1);
            sortJc1.setBounds(200,350,130,20);
            f.add(sortJc1);
            sortJc1.addActionListener(this);
            //read only current month statement from file
            try {
                String line;
                int balance =0;
                //read for income text
                BufferedReader br = new BufferedReader(new FileReader(uName + "/income.txt"));
                incomeArray = new ArrayList<String>(10);
                while ((line = br.readLine()) != null){
                    String[] splitByTab = line.split("\t");
                    String[] splitBySlash = splitByTab[0].split("/");
                    if(splitBySlash[1].equals(uMonth) && splitBySlash[2].equals(uYear)){
                        balance+=Integer.parseInt(splitByTab[2]);
                        //for sorting purpose
                        incomeArray.add(line);
                    }
                }
                sortView = new Sort();
                sortView.printData(model,incomeArray);
                br.close();
                //change the balance lebel
                totalBalanceLb.setText("Total Balance : "+ balance +" tk");
                totalBalanceLb.setBounds(900,00,300,15);
                f.add(totalBalanceLb);
                totalBalanceLb.setVisible(true);
                //red for cost text
                br = new BufferedReader(new FileReader(uName + "/cost.txt"));
                costArray = new ArrayList<String>(10);
                balance=0;
                while ((line = br.readLine()) != null){
                    String[] splitByTab = line.split("\t");
                    String[] splitBySlash = splitByTab[0].split("/");
                    if(splitBySlash[1].equals(uMonth) && splitBySlash[2].equals(uYear)){
                      //  model1.addRow(splitByTab);
                        balance+=Integer.parseInt(splitByTab[2]);
                        //for sorting purpose
                        costArray.add(line);
                    }
                }
                sortView.printData(model1,costArray);
                br.close();
                //change the balance lebel
                totalBalanceLb1.setText("Total Balance : "+ balance +" tk");
                totalBalanceLb1.setBounds(900,360,300,15);
                f.add(totalBalanceLb1);
                totalBalanceLb1.setVisible(true);
            }catch(Exception e){
                e.getStackTrace();
            }
        }
        public void viewSpecificDayTransaction(String uName,String date,JPanel f){
            incomeStatementLb.setText("Income Statement Of "+""+date);
            incomeStatementLb.setBounds(450,0,350,18);
            f.add(incomeStatementLb);
            font = new Font("Arial",Font.BOLD,18);
            incomeStatementLb.setFont(font);
            incomeStatementLb.setVisible(true);

            sortByLb.setBounds(150,0,50,15);
            f.add(sortByLb);
            sortJc.setBounds(200,0,130,20);
            f.add(sortJc);
            sortJc.addActionListener(this);
            costStatementLb.setText("Cost Statement Of "+""+date);
            costStatementLb.setBounds(450,350,350,18);
            f.add(costStatementLb);
            font = new Font("Arial",Font.BOLD,18);
            costStatementLb.setFont(font);
            costStatementLb.setVisible(true);

            sortByLb1.setBounds(150,350,50,15);
            f.add(sortByLb1);
            sortJc1.setBounds(200,350,130,20);
            f.add(sortJc1);
            sortJc1.addActionListener(this);
            //read only current month statement from file
            try {
                String line;
                int balance =0;

                System.out.println("date: "+date);
                //read for income text
                BufferedReader br = new BufferedReader(new FileReader(uName + "/income.txt"));
                incomeArray = new ArrayList<String>(10);
                while ((line = br.readLine()) != null){
                    String[] splitByTab = line.split("\t");
                    System.out.println(splitByTab[0]);
                    if(splitByTab[0].equals(date)){
                        balance+=Integer.parseInt(splitByTab[2]);
                        //for sorting purpose
                        incomeArray.add(line);
                    }
                }
                sortView = new Sort();
                sortView.printData(model,incomeArray);
                br.close();
                //change the balance lebel
                totalBalanceLb.setText("Total Balance : "+ balance +" tk");
                totalBalanceLb.setBounds(900,00,300,15);
                f.add(totalBalanceLb);
                totalBalanceLb.setVisible(true);
                //red for cost text
                br = new BufferedReader(new FileReader(uName + "/cost.txt"));
                costArray = new ArrayList<String>(10);
                balance=0;
                while ((line = br.readLine()) != null){
                    String[] splitByTab = line.split("\t");
                    if(splitByTab[0].equals(date)){
                        balance+=Integer.parseInt(splitByTab[2]);
                        //for sorting purpose
                        costArray.add(line);
                    }
                }
                sortView.printData(model1,costArray);
                br.close();
                //change the balance lebel
                totalBalanceLb1.setText("Total Balance : "+ balance +" tk");
                totalBalanceLb1.setBounds(900,360,300,15);
                f.add(totalBalanceLb1);
                totalBalanceLb1.setVisible(true);
            }catch(Exception e){
                e.getStackTrace();
            }
        }
    public void viewTransactionOnSpecificCategories(String uName, String cIncomeName, String cCostName, JPanel f)
    {
        incomeStatementLb.setText("Income Statement Of "+""+cIncomeName);
        incomeStatementLb.setBounds(450,0,350,18);
        f.add(incomeStatementLb);
        font = new Font("Arial",Font.BOLD,18);
        incomeStatementLb.setFont(font);
        incomeStatementLb.setVisible(true);


        sortByLb.setBounds(150,0,50,15);
        f.add(sortByLb);
        sortJc.setBounds(200,0,130,20);
        f.add(sortJc);
        sortJc.addActionListener(this);


        costStatementLb.setText("Cost Statement Of "+""+cCostName);
        costStatementLb.setBounds(450,350,350,18);
        f.add(costStatementLb);
        font = new Font("Arial",Font.BOLD,18);
        costStatementLb.setFont(font);
        costStatementLb.setVisible(true);

        sortByLb1.setBounds(150,350,50,15);
        f.add(sortByLb1);
        sortJc1.setBounds(200,350,130,20);
        f.add(sortJc1);
        sortJc1.addActionListener(this);


        try {
            String line;
            int balance = 0;
            //read for income text
            BufferedReader br = new BufferedReader(new FileReader(uName + "/income.txt"));
            incomeArray = new ArrayList<String>(10);
            while ((line = br.readLine()) != null) {
                String[] splitByTab = line.split("\t");
                //  String  year = uYear;//Integer.toString(uYear);
                if (splitByTab[1].equals(cIncomeName)) {
                    balance += Integer.parseInt(splitByTab[2]);
                    //for sorting purpose
                    incomeArray.add(line);
                }
            }
            sortView = new Sort();
            sortView.printData(model,incomeArray);
            br.close();
            //change the balance lebel
            totalBalanceLb.setText("Total Balance : "+ balance +" tk");
            totalBalanceLb.setBounds(900,0,300,15);
            f.add(totalBalanceLb);
            totalBalanceLb.setVisible(true);
            //red for cost text
            br = new BufferedReader(new FileReader(uName + "/cost.txt"));
            costArray = new ArrayList<String>(10);
            balance=0;
            while ((line = br.readLine()) != null){
                String[] splitByTab = line.split("\t");
                if (splitByTab[1].equals(cCostName)) {
                    balance += Integer.parseInt(splitByTab[2]);
                    //for sorting purpose
                    costArray.add(line);
                }
            }
            sortView.printData(model1,costArray);
            br.close();
            //change the balance lebel;
            totalBalanceLb1.setText("Total Balance : "+ balance +" tk");
            totalBalanceLb1.setBounds(900,360,300,15);
            f.add(totalBalanceLb1);
            totalBalanceLb1.setVisible(true);
        }catch(Exception ee){
            ee.getStackTrace();
        }
    }
       /* public void viewASpecificTimePeriodTransaction(String uName,String date1,String date2) {
            incomeStatementLb.setText("Income Statement Of " + "" + date1 + " to " + date2);
            costStatementLb.setText("Cost Statement Of " + "" + date1 + " to " + date2);
            //read only current month statement from file
            try {
                String line;
                int balance = 0;
                //read for income text
                BufferedReader br = new BufferedReader(new FileReader(uName + "/income.txt"));
                incomeArray = new ArrayList<String>(10);
                String[] date1_arr = date1.split("/");
                String[] date2_arr = date2.split("/");
                while ((line = br.readLine()) != null) {
                    String[] splitByTab = line.split("\t");
                    String[] splitBySlash = splitByTab[0].split("/");
                    if (splitByTab[0].equals(date1)) {
                        if (date2_arr[2] > date1_arr[2]) {
                            {

                                balance += Integer.parseInt(splitByTab[2]);
                                //for sorting purpose
                                incomeArray.add(line);
                            }

                        }

                    else{
                            JOptionPane.showMessageDialog(null, "Your Input Doesn't exists", "messege", JOptionPane.OK_OPTION);
                        }
                    }
                    sortView = new Sort();
                    sortView.printData(model, incomeArray);
                    br.close();
                    //change the balance lebel
                    totalBalanceLb.setText("Total Balance : " + balance + " tk");
                    //red for cost text
                    br = new BufferedReader(new FileReader(uName + "/cost.txt"));
                    costArray = new ArrayList<String>(10);
                    balance = 0;
                    while ((line = br.readLine()) != null) {
                        String[] splByTab = line.split("\t");
                        if (splitByTab[0].equals(date1)) {
                            model1.addRow(splitByTab);
                            balance += Integer.parseInt(splitByTab[2]);
                            //for sorting purpose
                            costArray.add(line);
                        } else {
                            JOptionPane.showMessageDialog(null, "Your Input Doesn't exists", "messege", JOptionPane.OK_OPTION);
                        }
                    }
                    sortView.printData(model, incomeArray);
                    br.close();
                    //change the balance lebel
                    totalBalanceLb1.setText("Total Balance : " + balance + " tk");
                }

            }catch(Exception e1) {
                e1.getStackTrace();
            }
        }*/
    @Override
    public void actionPerformed(ActionEvent e) {
        JComboBox cb = (JComboBox) e.getSource();
        String newSelection = (String) cb.getSelectedItem();
        if(newSelection.equals("Ascending by amount")){
            List<String> a=sortView.ascendingAmount(incomeArray);
            sortView.printData(model,a);
        }
        if(newSelection.equals("Ascending by amount ")){
            List<String> a=sortView.ascendingAmount(costArray);
            sortView.printData(model1,a);
        }
    }
}