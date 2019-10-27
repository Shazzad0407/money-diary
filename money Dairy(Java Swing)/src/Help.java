import javax.swing.*;
import java.awt.*;

/**
 * Created by Fakrul Uddin on 1/3/2017.
 */
public class Help {
    public Help(){
        String messege = "welcome to Money Manager ";
        String me= "below some instructions that may help you for a better experience";
        JFrame f = new JFrame("Help");
        f.setResizable(false);
        JLabel lb = new JLabel(messege);
        lb.setBounds(160,20,350,20);
        JLabel l = new JLabel(me);
        l.setBounds(30,40,580,20);
        Font f1 = new  Font("Arial",Font.CENTER_BASELINE,18);
        lb.setFont(f1);
        lb.setForeground(Color.red);
        l.setFont(f1);
        l.setForeground(Color.PINK);
        String messege1= "* To add income/cost click on \"Add New Transactions\" menu";
        String messege2= "* To add View your statistic click on \"View Transection History\" menu";
        String messege3= "* To modify/delete any transaction click on \"Modify/Delete Data\" menu";
        String messege4= "* To search Specific day transaction give input in dd/mm/yy formet. EX: 22/Jan/2016";
        String messege5= "* always use first 3 lettter of month & 1st letter shoud in capital";
        JLabel lb1 = new JLabel(messege1);
        JLabel lb2 = new JLabel(messege2);
        JLabel lb3 = new JLabel(messege3);
        JLabel lb4 = new JLabel(messege4);
        JLabel lb5 = new JLabel(messege5);
        lb1.setBounds(80,90,600,20);
        lb2.setBounds(80,120,600,20);
        lb3.setBounds(80,150,600,20);
        lb4.setBounds(80,180,600,20);
        lb5.setBounds(80,210,600,20);
        Container c = f.getContentPane();
        c.setLayout(null);
        c.add(lb);c.add(l); c.add(lb1);c.add(lb2); c.add(lb3);c.add(lb4); c.add(lb5);
        f.setBounds(250,100,700,400);
        f.setVisible(true);


    }

}
