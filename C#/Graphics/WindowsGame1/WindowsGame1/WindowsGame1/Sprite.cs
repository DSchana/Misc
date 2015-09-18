using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Graphics;

namespace WindowsGame1
{
    public class Sprite
    {
        // The position of the Sprite
        public Vector2 position;

        // The texture object used when drawing the sprite
        private Texture2D mSpriteTexture;

        // Constructors
        public Sprite(int X, int Y)
        {
            position = new Vector2(X, Y);
        }

        public Sprite()
        {
            position = new Vector2(0, 0);
        }

        // Method
        // ========================================================================

        // Load the texture for the sprite using the Content Pipeline
        public void loadContent(ContentManager theContentManager, string assetName)
        {
            mSpriteTexture = theContentManager.Load<Texture2D>(assetName);
        }

        // Update x and y position of sprite
        public void update(int X, int Y)
        {
            position.X = X;
            position.Y = Y;
        }

        // Display sprite on screen
        public void render(SpriteBatch theSpriteBatch)
        {
            theSpriteBatch.Draw(mSpriteTexture, position, Color.White);
        }
    }
}
