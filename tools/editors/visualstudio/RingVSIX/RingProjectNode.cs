using System;
using System.Collections.Generic;
using Microsoft.VisualStudio.Project;

using System.Drawing;
using System.Windows.Forms;
using System.IO;

namespace RingTeam.RingVSIX
{
    public class RingProjectNode : ProjectNode
    {
        internal static int imageIndex;
        public override int ImageIndex
        {
            get { return imageIndex; }
        }

        private RingProjectPackage package;

        private static ImageList imageList;

        public RingProjectNode(RingProjectPackage package)
        {
            this.package = package;

            imageIndex = this.ImageHandler.ImageList.Images.Count;

            foreach (Image img in imageList.Images)
            {
                this.ImageHandler.AddImage(img);
            }

        }


        static RingProjectNode()
        {
            imageList = Utilities.GetImageList(typeof(RingProjectNode).Assembly.GetManifestResourceStream("RingTeam.RingVSIX.Resources.RingNode.bmp"));
        }

        public override Guid ProjectGuid
        {
            get { return RingGuidList.guidRingVSIXFactory; }
        }
        public override string ProjectType
        {
            get { return "RingProjectType"; }
        }

        public override void AddFileFromTemplate(
            string source, string target)
        {
            string nameSpace =
             this.FileTemplateProcessor.GetFileNamespace(target, this);
            string className = Path.GetFileNameWithoutExtension(target);

            this.FileTemplateProcessor.AddReplace("$nameSpace$", nameSpace);
            this.FileTemplateProcessor.AddReplace("$className$", className);

            this.FileTemplateProcessor.UntokenFile(source, target);
            this.FileTemplateProcessor.Reset();
        }

        protected override Guid[] GetConfigurationIndependentPropertyPages()
        {
            Guid[] result = new Guid[1];
            result[0] = typeof(GeneralPropertyPage).GUID;
            return result;
        }
        protected override Guid[] GetPriorityProjectDesignerPages()
        {
            Guid[] result = new Guid[1];
            result[0] = typeof(GeneralPropertyPage).GUID;
            return result;
        }
    }
}
