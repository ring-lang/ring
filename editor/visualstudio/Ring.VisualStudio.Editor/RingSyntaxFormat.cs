using System.ComponentModel.Composition;
using System.Windows.Media;
using Microsoft.VisualStudio.Text.Classification;
using Microsoft.VisualStudio.Utilities;

namespace Ring.VisualStudio.TextEditor
{
    class RingSyntaxFormat
    {
        #region Format definition
        /// <summary>
        /// Defines an editor format for the Ring type that has a purple background
        /// and is underlined.
        /// </summary>
        [Export(typeof(EditorFormatDefinition))]
        [ClassificationType(ClassificationTypeNames = "Ring")]
        [Name("Ring")]
        [UserVisible(true)] //this should be visible to the end user
        [Order(Before = Priority.Default)] //set the priority to be after the default classifiers
        internal sealed class RingFormat : ClassificationFormatDefinition
        {
            /// <summary>
            /// Defines the visual format for the "Ring" classification type
            /// </summary>
            public RingFormat()
            {
                this.DisplayName = "Ring"; //human readable version of the name
                this.ForegroundColor = Colors.OrangeRed;
            }
        }
        #endregion //Format definition

        #region Format definition
        /// <summary>
        /// Defines an editor format for the Ring type that has a purple background
        /// and is underlined.
        /// </summary>
        [Export(typeof(EditorFormatDefinition))]
        [ClassificationType(ClassificationTypeNames = "RingNumeric")]
        [Name("RingNumeric")]
        [UserVisible(true)] //this should be visible to the end user
        [Order(Before = Priority.Default)] //set the priority to be after the default classifiers
        internal sealed class RingNumericFormat : ClassificationFormatDefinition
        {
            /// <summary>
            /// Defines the visual format for the "Ring" classification type
            /// </summary>
            public RingNumericFormat()
            {
                this.DisplayName = "RingNumeric"; //human readable version of the name
                this.ForegroundColor = Colors.Goldenrod;
            }
        }
        #endregion //Format definition
    }
}
