using System;
using System.Collections.Generic;
using System.ComponentModel.Composition;
using Microsoft.VisualStudio.Text;
using Microsoft.VisualStudio.Text.Classification;
using Microsoft.VisualStudio.Utilities;
using Microsoft.VisualStudio.Language.StandardClassification;
using System.Text.RegularExpressions;

namespace Ring.VisualStudio.TextEditor
{
    #region Provider definition
    /// <summary>
    /// This class causes a classifier to be added to the set of classifiers. Since
    /// the content type is set to "text", this classifier applies to all text files
    /// </summary>
    [Export(typeof(IClassifierProvider))]
    [ContentType("ring")]
    internal class RingProvider : IClassifierProvider
    {
        /// <summary>
        /// Import the classification registry to be used for getting a reference
        /// to the custom classification type later.
        /// </summary>
        [Import]
        internal IClassificationTypeRegistryService ClassificationRegistry = null;

        public IClassifier GetClassifier(ITextBuffer buffer)
        {
            return buffer.Properties.GetOrCreateSingletonProperty<Ring>(delegate { return new Ring(ClassificationRegistry); });
        }
    }
    #endregion //provider def

    #region Classifier
    /// <summary>
    /// Classifier that classifies all text as an instance of the OrinaryClassifierType
    /// </summary>
    class Ring : IClassifier
    {
        RingLanguage _RingLanguage;
        IClassificationType _classificationType;
        IClassificationType _whiteSpaceType;
        IClassificationType _keywordType;
        IClassificationType _commentType;
        IClassificationType _stringType;
        IClassificationType _identifierType;
        IClassificationType _numericType;

        internal Ring(IClassificationTypeRegistryService registry)
        {
            _RingLanguage = new RingLanguage();
            _classificationType = registry.GetClassificationType("Ring");
            _whiteSpaceType = registry.GetClassificationType(
                          PredefinedClassificationTypeNames.WhiteSpace);
            _keywordType = registry.GetClassificationType(
                          PredefinedClassificationTypeNames.Keyword);
            _commentType = registry.GetClassificationType(
                          PredefinedClassificationTypeNames.Comment);
            _stringType = registry.GetClassificationType(
                          PredefinedClassificationTypeNames.String);
            _identifierType = registry.GetClassificationType(
                          PredefinedClassificationTypeNames.Operator);
            _numericType = registry.GetClassificationType("RingNumeric");
        }

        /// <summary>
        /// This method scans the given SnapshotSpan for potential matches for this
        /// classification.
        /// In this instance, it classifies everything and returns each span as a
        /// new ClassificationSpan.
        /// </summary>
        /// <param name="trackingSpan">The span currently being classified</param>
        /// <returns>A list of ClassificationSpans that represent spans identified
        /// to be of this classification</returns>
        public IList<ClassificationSpan> GetClassificationSpans(SnapshotSpan span)
        {
            //create a list to hold the results
            List<ClassificationSpan> classifications = new List<ClassificationSpan>();
            string current = span.GetText();
            bool commentFound = false;
            // Note:  Comments should go to the end of the line.
            foreach (var item in _RingLanguage.Comments)
            {
                Regex reg = new Regex(item, RegexOptions.IgnoreCase);
                var matches = reg.Matches(current);
                for (int i = 0; i < matches.Count; i++)
                {
                    commentFound = true;
                    Match m = matches[i];
                    Span new_span = new Span(span.Start.Position + m.Index,
                                          current.Length - m.Index);
                    SnapshotSpan new_snapshot = new SnapshotSpan(span.Snapshot,
                                          new_span);
                    var newText = new_snapshot.GetText();
                    classifications.Add(new ClassificationSpan(new_snapshot,
                                          _commentType));
                }
            }
            if (commentFound)
                return classifications;
            Classify(classifications, current, span, _RingLanguage.Quoted,
                          _stringType);
            Classify(classifications, current, span, _RingLanguage.KeyWords,
                          _keywordType);
            Classify(classifications, current, span, _RingLanguage.IdentifierTypes,
                          _identifierType);
            Classify(classifications, current, span, _RingLanguage.Numeric,
                          _numericType);
            return classifications;
        }
        private void Classify(List<ClassificationSpan> classifications, string current,
                  SnapshotSpan span, List<string> matchList, IClassificationType classificationType)
        {
            foreach (var item in matchList)
            {
                Regex reg = new Regex(item, RegexOptions.IgnoreCase);
                var matches = reg.Matches(current);
                for (int i = 0; i < matches.Count; i++)
                {
                    Match m = matches[i];
                    Span new_span = new Span(span.Start.Position + m.Index, m.Length);
                    SnapshotSpan new_snapshot = new SnapshotSpan(span.Snapshot, new_span);
                    var newText = new_snapshot.GetText();
                    classifications.Add(new ClassificationSpan(new_snapshot,
                                          classificationType));
                }
            }
        }

#pragma warning disable 67
        // This event gets raised if a non-text change would affect the classification
        // in some way, for example typing /* would cause the classification to
        // change in C# without directly affecting the span.
        public event EventHandler<ClassificationChangedEventArgs> ClassificationChanged;
#pragma warning restore 67
    }
    #endregion //Classifier
}
