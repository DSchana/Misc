/* In thi program:
 * Load and display image
 * Move image accross screen
 * Getting mouse coordinates
 * Getting mouse button states
 * Create generic list of Sprite objects
 **/

using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;

namespace WindowsGame1
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Microsoft.Xna.Framework.Game
    {
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;

        List<Sprite> copy_sprite = new List<Sprite>();

        // Sprite object from sprite class
        Sprite mSprite;

        ButtonState oldLeftState;
        ButtonState oldRightState;

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // TODO: Add your initialization logic here
            mSprite = new Sprite();

            base.Initialize();
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpritenBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);

            // TODO: use this.Content to load your game content here
            // load rishi into texture
            mSprite.loadContent(this.Content, "rishi");
        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// all content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {
            // Allows the game to exit
            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed) 
                this.Exit();

            // TODO: Add your update logic here
            int new_x = Mouse.GetState().X;
            int new_y = Mouse.GetState().Y;

            // Set rishi's x, y to mouse x, y
            mSprite.update(new_x, new_y);

            // Check for mouse click
            if (Mouse.GetState().LeftButton == ButtonState.Pressed && oldLeftState != ButtonState.Pressed)
            {
                Sprite add_copy = new Sprite(new_x, new_y);  // copy of sprite at position of click
                add_copy.loadContent(this.Content, "rishi");  // Load rishi into copy sprite before adding to list

                copy_sprite.Add(add_copy);
            }

            // Clear rishi
            if (Mouse.GetState().RightButton == ButtonState.Pressed && oldRightState != ButtonState.Pressed)
            {
                if (copy_sprite.Count != 0)
                {
                    copy_sprite.RemoveAt(copy_sprite.Count - 1);
                }
            }

            oldLeftState = Mouse.GetState().LeftButton;
            oldRightState = Mouse.GetState().RightButton;

            base.Update(gameTime);
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.Aquamarine);

            // TODO: Add your drawing code here
            spriteBatch.Begin();            
            if (copy_sprite.Count != 0)  // make sure list is not empty before attempting to render image
            {
                // draw all copies of rishi to screen
                for (int i = 0; i < copy_sprite.Count; i++)
                {
                    copy_sprite.ElementAt(i).render(this.spriteBatch);
                } 

            }

            // draw the original rishi to screen
            mSprite.render(this.spriteBatch);
               
            spriteBatch.End();

            base.Draw(gameTime);
        }
    }
}
