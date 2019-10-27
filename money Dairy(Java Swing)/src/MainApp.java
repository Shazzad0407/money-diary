import javax.swing.*;

/**
 * Created by Fakrul Uddin on 12/24/2016.
 */
public class MainApp {
    public static void main(String[] args) {
        try{
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
            JFrame.setDefaultLookAndFeelDecorated(true);
        }catch (Exception e){
            System.out.println("Could not load System look.");
        }
        Login login = new Login();
    }
}
