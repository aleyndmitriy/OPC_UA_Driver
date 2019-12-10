/*****************************************************************************
*                                                                            *
*                     SOFTING Industrial Automation GmbH                     *
*                          Richard-Reitzner-Allee 6                          *
*                                D-85540 Haar                                *
*                        Phone: ++49-89-4 56 56-0                            *
*                          Fax: ++49-89-4 56 56-3 99                         *
*                                                                            *
*                            SOFTING CONFIDENTIAL                            *
*                                                                            *
*                     Copyright (C) SOFTING IA GmbH 2019                     *
*                             All Rights Reserved                            *
*                                                                            *
* NOTICE: All information contained herein is, and remains the property of   *
*   SOFTING Industrial Automation GmbH and its suppliers, if any. The intel- *
*   lectual and technical concepts contained herein are proprietary to       *
*   SOFTING Industrial Automation GmbH and its suppliers and may be covered  *
*   by German and Foreign Patents, patents in process, and are protected by  *
*   trade secret or copyright law. Dissemination of this information or      *
*   reproduction of this material is strictly forbidden unless prior         *
*   written permission is obtained from SOFTING Industrial Automation GmbH.  *
******************************************************************************
******************************************************************************
*                                                                            *
* PROJECT_NAME             dataFEED OPC UA C++ Server & Client SDK           *
*                                                                            *
* VERSION                  5.61.0                                            *
*                                                                            *
* DATE                     05.11.2019                                        *
*                                                                            *
*****************************************************************************/

#ifndef SERVERAGGREGATEFUNCTION_H
#define SERVERAGGREGATEFUNCTION_H
#if TB5_HISTORY
#include "Base.h"
#include "Enums.h"
#include "ServerObject.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This class represents an aggregate function (e.g. 'Average'). Servers should create an
		* AggregateFunction object for every aggregate function they support. */
		class TBC_EXPORT AggregateFunction
			: public Object
		{
		public:
			/*! Constructs a new AggregateFunction instance */
			static ObjectPointer<AggregateFunction> create();

			/*! Constructs a new AggregateFunction instance with mandatory attributes */
			static ObjectPointer<AggregateFunction> create(const INodeId& nodeId,
				const ILocalizedText& displayName,
				const IQualifiedName& browseName,
				const ILocalizedText& description);

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			AggregateFunction(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			AggregateFunction();
			/*! Constructs a new AggregateFunction instance with mandatory attributes. */
			AggregateFunction(const INodeId& nodeId,
				const ILocalizedText& displayName,
				const IQualifiedName& browseName,
				const ILocalizedText& description);

		public:
			/*! Destructor */
			virtual ~AggregateFunction();

			/////////////////////////////////////////////////////////////////////////
			// Static Methods of class AggregateFunction
			/////////////////////////////////////////////////////////////////////////

			/*! Factory method for creating the aggregate function object for the 'Interpolative' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createInterpolativeFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'Average' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createAverageFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'TimeAverage' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createTimeAverageFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'TimeAverage2' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createTimeAverage2FunctionObject();

			/*! Factory method for creating the aggregate function object for the 'Total' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createTotalFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'Total2' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createTotal2FunctionObject();

			/*! Factory method for creating the aggregate function object for the 'Minimum' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createMinimumFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'Maximum' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createMaximumFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'MinimumActualTime' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createMinimumActualTimeFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'MaximumActualTime' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createMaximumActualTimeFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'Range' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createRangeFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'Minimum2' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createMinimum2FunctionObject();

			/*! Factory method for creating the aggregate function object for the 'Maximum2' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createMaximum2FunctionObject();

			/*! Factory method for creating the aggregate function object for the 'MinimumActualTime2' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createMinimumActualTime2FunctionObject();

			/*! Factory method for creating the aggregate function object for the 'MaximumActualTime2' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createMaximumActualTime2FunctionObject();

			/*! Factory method for creating the aggregate function object for the 'Range2' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createRange2FunctionObject();

			/*! Factory method for creating the aggregate function object for the 'Count' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createCountFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'DurationInStateZero' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createDurationInStateZeroFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'DurationInStateNonZero' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createDurationInStateNonZeroFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'NumberOfTransitions' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createNumberOfTransitionsFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'Start' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createStartFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'End' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createEndFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'Delta' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createDeltaFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'StartBound' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createStartBoundFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'EndBound' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createEndBoundFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'DeltaBounds' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createDeltaBoundsFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'DurationGood' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createDurationGoodFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'DurationBad' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createDurationBadFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'PercentGood' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createPercentGoodFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'PercentBad' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createPercentBadFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'WorstQuality' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createWorstQualityFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'WorstQuality2' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createWorstQuality2FunctionObject();

			/*! Factory method for creating the aggregate function object for the 'AnnotationCount' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createAnnotationCountFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'StandardDeviationSample' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createStandardDeviationSampleFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'VarianceSample' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createVarianceSampleFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'StandardDeviationPopulation' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createStandardDeviationPopulationFunctionObject();

			/*! Factory method for creating the aggregate function object for the 'VariancePopulation' aggregate.
			* If the object already exists, the existing node is returned. */
			static ObjectPointer<AggregateFunction> createVariancePopulationFunctionObject();

		private:
			/*! Forbid use assignment operator */
			AggregateFunction& operator=(const AggregateFunction&);
			/*! Forbid use of copy constructor */
			AggregateFunction(const AggregateFunction&);
		};
		typedef ObjectPointer<AggregateFunction> AggregateFunctionPtr;
		typedef ObjectPointer<const AggregateFunction> AggregateFunctionConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAGGREGATEFUNCTION_H
