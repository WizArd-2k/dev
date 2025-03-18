package com.example;

import static org.junit.Assert.assertTrue;

import org.junit.Test;
import org.bukkit.plugin.java.JavaPlugin;
import org.bukkit.plugin.PluginDescriptionFile;
import org.bukkit.plugin.InvalidDescriptionException;

/**
 * Unit test for simple App.
 */
public class AppTest 
{
    /**
     * Rigorous Test :-)
     */
    @Test
    public void shouldAnswerWithTrue()
    {
        assertTrue( true );
    }

    @Test
    public void testPluginDescription() throws InvalidDescriptionException {
        PluginDescriptionFile pdf = new PluginDescriptionFile("MyPlugin", "1.0", "com.example.MyPlugin");
        assertTrue(pdf.getName().equals("MyPlugin"));
        assertTrue(pdf.getVersion().equals("1.0"));
        assertTrue(pdf.getMain().equals("com.example.MyPlugin"));
    }
}
