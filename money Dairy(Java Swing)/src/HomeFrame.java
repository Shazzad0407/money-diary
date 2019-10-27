import javafx.scene.paint.*;

import javax.swing.*;
import javax.swing.event.MenuEvent;
import javax.swing.event.MenuListener;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

public class HomeFrame extends ViewTransection implements ActionListener{
    JMenuBar bar;
    JFrame frame;
    JMenu file, newTransaction, viewStatistics, modifyData, setting, help;
    JMenuItem saveAs,print,logOut, exit;
    JMenuItem addIncome,addCost;
    JMenuItem viewCurrentMonthTrasactions,viewATimePeriodTransactions,viewSpecificYearTransactions, viewSpecificMonthTransactions, viewSpecificDayTransactions,viewSpecificTypeTransaction, viewAllTransactions;
    JMenuItem searchTransactionFromCost,searchTransactionFromIncome;
    JMenuItem AddIncomeCategory,AddExpensesCategory,currencySetting,themeSetting,profileSetting;
    JPanel mainPanel,p1,p2,p3,p4,p5,p6,p7;
    DefaultTableModel model, model1;
    String userName;
    int uInputYear  = 0;
    Container c;
    public HomeFrame (){}
    public HomeFrame( String userName){
        frame = new JFrame();
        frame.setTitle("Home Page");
        this.userName = userName;
        c = frame.getContentPane();
        c.setLayout(null);
        /*menuPane = new JPanel(new FlowLayout(-2));
        menuPane.setBackground(Color.gray);
        c.add(menuPane,BorderLayout.NORTH);*/
        //menuBer
        bar = new JMenuBar();
        bar.setBackground(Color.lightGray);
        frame.setJMenuBar(bar);
        //menu
        file = new JMenu(" File ");
        newTransaction = new JMenu(" Add New Transections ");
        viewStatistics = new JMenu(" View Transection History ");
        modifyData = new JMenu(" Modify/Delete Data ");
        setting = new JMenu(" Settings ");
        help= new JMenu(" Help ");
       //addinng menu on menubar
        bar.add(file);
        bar.add(newTransaction);
        bar.add(viewStatistics);
        bar.add(modifyData);
        bar.add(setting);
        bar.add(help);
        //MenueItem for File menu
        saveAs = new JMenuItem("Save As");
        print = new JMenuItem("Print");
        logOut = new JMenuItem("Log Out");
        exit = new JMenuItem("Exit");
        //add menuItem in fileMenue
        file.add(saveAs);
        file.add(print);
        file.add(logOut);
        file.add(exit);
        //MenueItem for  "New Transections menu"
        addIncome = new JMenuItem("Add Income");
        addCost = new JMenuItem("Add Cost");
        //add Add New Transections Items in newTransection menu
        newTransaction.add(addIncome);
        newTransaction.add(addCost);
        //MenueItem for ViewStatistics menu
        viewCurrentMonthTrasactions = new JMenuItem("View Current Month Transactions");
        viewATimePeriodTransactions = new JMenuItem("View A Time Period Transactions");
        viewSpecificYearTransactions = new JMenuItem("View Specific Year Transactions");
        viewSpecificMonthTransactions = new JMenuItem("View Specific Month Transactions");
        viewSpecificDayTransactions = new JMenuItem("View Specific Day Transactions");
        viewSpecificTypeTransaction = new JMenuItem("View Transactions On Specific Categories");
        viewAllTransactions = new JMenuItem("View All Transactions");
        //Add ViewStatistics Items in "View Transection History" menu
        viewStatistics.add(viewCurrentMonthTrasactions);
        viewStatistics.add(viewATimePeriodTransactions);
        viewStatistics.add(viewSpecificYearTransactions);
        viewStatistics.add(viewSpecificMonthTransactions);
        viewStatistics.add(viewSpecificDayTransactions);
        viewStatistics.add(viewSpecificTypeTransaction);
        viewStatistics.add(viewAllTransactions);

        //MenueItem for  modify menu
        searchTransactionFromIncome = new JMenuItem("Search Transactions From Income ");
        searchTransactionFromCost = new JMenuItem("Search Transactions From Cost");

        //Add Modify Items in "Modify/Delete Data" menu
        modifyData.add(searchTransactionFromIncome);
        modifyData.add(searchTransactionFromCost);

        //MenueItem for Setting menu
        AddIncomeCategory = new JMenuItem("Add Income Category");
        AddExpensesCategory = new JMenuItem("Add Expense Category");
        currencySetting = new JMenuItem("Currency Settings");
        themeSetting = new JMenuItem("Theme Settings");
        profileSetting = new JMenuItem("Profile Settings");
        //Add MenueItems in "Settings" menu
        setting.add(AddIncomeCategory);
        setting.add(AddExpensesCategory);
        setting.add(currencySetting);
        setting.add(themeSetting);
        setting.add(profileSetting);

        model = new DefaultTableModel();
        model1 = new DefaultTableModel();


        mainPanel = new JPanel(null);
        mainPanel.setBounds(0,50,1200,800);
       // mainPanel.setBackground(Color.GREEN);

        p1 = new JPanel(null);
        p1.setBounds(0,0,1200,800);
     //   p1.setBackground(Color.RED);
        viewTransection(p1,model,model1);

        p2 = new JPanel(null);
        p2.setBounds(0,0,1200,800);
       // p2.setBackground(Color.LIGHT_GRAY);
        viewTransection(p2,model,model1);

        p3 = new JPanel(null);
        p3.setBounds(0,0,1200,800);
        // p2.setBackground(Color.LIGHT_GRAY);
        viewTransection(p3,model,model1);

        p4 = new JPanel(null);
        p4.setBounds(0,0,1200,800);
        // p2.setBackground(Color.LIGHT_GRAY);
        viewTransection(p4,model,model1);

        p5 = new JPanel(null);
        p5.setBounds(0,0,1200,800);
        // p2.setBackground(Color.LIGHT_GRAY);
        viewTransection(p5,model,model1);

        p6 = new JPanel(null);
        p6.setBounds(0,0,1200,800);
        // p2.setBackground(Color.LIGHT_GRAY);
        viewTransection(p6,model,model1);

        c.add(mainPanel);



        //Action listener impliment
        addIncome.addActionListener(this);
        addCost.addActionListener(this);
        viewCurrentMonthTrasactions.addActionListener(this);
        viewAllTransactions.addActionListener(this);
        viewSpecificYearTransactions.addActionListener(this);
        viewSpecificMonthTransactions.addActionListener(this);
        viewSpecificDayTransactions.addActionListener(this);
        viewSpecificTypeTransaction.addActionListener(this);
        viewATimePeriodTransactions.addActionListener(this);
        searchTransactionFromIncome.addActionListener(this);
        searchTransactionFromCost.addActionListener(this);

        help.addMenuListener(new MenuListener() {
            @Override
            public void menuSelected(MenuEvent e) {
                new Help();
            }

            @Override
            public void menuDeselected(MenuEvent e) {

            }

            @Override
            public void menuCanceled(MenuEvent e) {

            }
        });




        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setBounds(0,0,1200,800);
        frame.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == addIncome){
            new AddedIncome(userName);
        }//end of addIncome
        else if(e.getSource() == addCost)
        {
            new AddedCost(userName);
        }
        else if(e.getSource() == viewCurrentMonthTrasactions)
        {

            mainPanel.removeAll();
            mainPanel.repaint();
            mainPanel.revalidate();

            mainPanel.add(p1);
            mainPanel.repaint();
            mainPanel.revalidate();

            currentMonthTransection(userName,p1);

            /*ViewTransection view = new ViewTransection();
            view.viewTransection(frame);//passing frame in viewTransection method;
            view.currentMonthTransection(userName);*/

        }
        else if(e.getSource() == viewAllTransactions)
        {
            mainPanel.removeAll();
            mainPanel.repaint();
            mainPanel.revalidate();

            mainPanel.add(p2);
            mainPanel.repaint();
            mainPanel.revalidate();

            viewAllTansaction(userName,p2);
           /* ViewTransection view = new ViewTransection();
            view.viewTransection(frame);
            view.viewAllTansaction(userName);//passing frame in viewTransection method;*/
        }
        else if(e.getSource() == viewSpecificYearTransactions)
        {
            JTextField jp = new JTextField();
            jp.setBounds(20,20,40,20);
            int choice = JOptionPane.showConfirmDialog(null,jp,"Enter Your Year",JOptionPane.OK_CANCEL_OPTION);
            if(choice == JOptionPane.OK_OPTION) {
                mainPanel.removeAll();
                mainPanel.repaint();
                mainPanel.revalidate();

                mainPanel.add(p3);
                mainPanel.repaint();
                mainPanel.revalidate();

                viewSpecificYearTransaction(userName, jp.getText(),p3);
            }
        }
        else if(e.getSource() == viewSpecificMonthTransactions)
        {
            mainPanel.removeAll();
            mainPanel.repaint();
            mainPanel.revalidate();

            mainPanel.add(p4);
            mainPanel.repaint();
            mainPanel.revalidate();

            JPanel panelForSpecificMonth;
            panelForSpecificMonth = new JPanel();
            panelForSpecificMonth.setBounds(20,20,250,200);
            panelForSpecificMonth.setBackground(Color.cyan);
            panelForSpecificMonth.setLayout(null);

            JLabel monthLb,yearLb;
            monthLb= new JLabel("Month : ");
            monthLb.setBounds(20,20,60,20);
            yearLb = new JLabel("Year : ");
            yearLb.setBounds(20,60,60,20);

            JTextField monthTf,yearTf;
            monthTf = new JTextField();
            monthTf.setBounds(80,20,120,20);
            yearTf = new JTextField();
            yearTf.setBounds(80,60,120,20);
            panelForSpecificMonth.add(monthLb);
            panelForSpecificMonth.add(monthTf);
            panelForSpecificMonth.add(Box.createHorizontalStrut(15));
            panelForSpecificMonth.add(yearLb);
            panelForSpecificMonth.add(yearTf);
            UIManager.put("OptionPane.minimumSize",new Dimension(400,200));
            int choice = JOptionPane.showConfirmDialog(null,panelForSpecificMonth,"Enter Your Month",JOptionPane.OK_CANCEL_OPTION);

           if(choice == JOptionPane.OK_OPTION)
           {
                viewSpecificMonthTransaction( userName,monthTf.getText(),yearTf.getText(),p4);
           }
        }
        else if(e.getSource() == viewSpecificDayTransactions)
        {

            JTextField jp = new JTextField();
            jp.setBounds(20,20,40,20);
            int choice = JOptionPane.showConfirmDialog(null,jp,"Enter Your Date",JOptionPane.OK_CANCEL_OPTION);
            if(choice == JOptionPane.OK_OPTION) {
                mainPanel.removeAll();
                mainPanel.repaint();
                mainPanel.revalidate();

                mainPanel.add(p5);
                mainPanel.repaint();
                mainPanel.revalidate();
                viewSpecificDayTransaction(userName, jp.getText(),p5);
            }
        }
        else if(e.getSource() == viewSpecificTypeTransaction)
        {
            JPanel panelForSpecificMonth;
            panelForSpecificMonth = new JPanel();
            panelForSpecificMonth.setBounds(20,20,300,200);
            panelForSpecificMonth.setBackground(Color.cyan);
            panelForSpecificMonth.setLayout(null);
            JLabel categoryLb1,categoryLb2;
            categoryLb1 = new JLabel("Category of Income : ");
            categoryLb1.setBounds(20,20,150,20);
            categoryLb2 = new JLabel("Category of Cost : ");
            categoryLb2.setBounds(20,50,150,20);

            JTextField category1Tf,category2Tf;
            category1Tf = new JTextField();
            category1Tf.setBounds(190,20,120,20);
            category2Tf = new JTextField();
            category2Tf.setBounds(190,50,120,20);
            panelForSpecificMonth.add(categoryLb1);
            panelForSpecificMonth.add(category1Tf);
            panelForSpecificMonth.add(categoryLb2);
            panelForSpecificMonth.add(category2Tf);
            panelForSpecificMonth.add(Box.createHorizontalStrut(15));
            UIManager.put("OptionPane.minimumSize",new Dimension(400,200));
            int choice = JOptionPane.showConfirmDialog(null,panelForSpecificMonth,"Enter Your Category",JOptionPane.OK_CANCEL_OPTION);
            if(choice == JOptionPane.OK_OPTION)
            {
                mainPanel.removeAll();
                mainPanel.repaint();
                mainPanel.revalidate();

                mainPanel.add(p6);
                mainPanel.repaint();
                mainPanel.revalidate();
                viewTransactionOnSpecificCategories(userName,category1Tf.getText(),category2Tf.getText(),p6);
            }

        }
        /*
        else if(e.getSource() == viewATimePeriodTransactions){
            mainPanel.removeAll();
            mainPanel.repaint();
            mainPanel.revalidate();

            mainPanel.add(p6);
            mainPanel.repaint();
            mainPanel.revalidate();
            JPanel panelForSpecificMonth;
            panelForSpecificMonth = new JPanel();
            panelForSpecificMonth.setBounds(20,20,250,200);
            panelForSpecificMonth.setBackground(Color.cyan);
            panelForSpecificMonth.setLayout(null);

            JLabel date1Lb,date2Lb;
            date1Lb= new JLabel("Date1 : ");
            date1Lb.setBounds(20,20,60,20);
            date2Lb = new JLabel("Date2 : ");
            date2Lb.setBounds(20,60,60,20);

            JTextField date1Tf,date2Tf;
            date1Tf = new JTextField();
            date1Tf.setBounds(80,20,120,20);
            date2Tf = new JTextField();
            date2Tf.setBounds(80,60,120,20);
            panelForSpecificMonth.add(date1Lb);
            panelForSpecificMonth.add(date1Tf);
            panelForSpecificMonth.add(Box.createHorizontalStrut(15));
            panelForSpecificMonth.add(date2Lb);
            panelForSpecificMonth.add(date2Tf);
            UIManager.put("OptionPane.minimumSize",new Dimension(400,200));
            int choice = JOptionPane.showConfirmDialog(null,panelForSpecificMonth,"Enter Your Month",JOptionPane.OK_CANCEL_OPTION);

            if(choice == JOptionPane.OK_OPTION)
            {
                viewTransection(frame);
               // view.viewASpecificTimePeriodTransaction( userName,date1Tf.getText(),date2Tf.getText());
            }

        }*/
        else if(e.getSource() == searchTransactionFromIncome)
        {
            new DeleteOrModifyByIncome(userName);
        }
        else if(e.getSource() == searchTransactionFromCost)
        {
            new DeleteOrModifyByCost(userName);
        }
    }

}
