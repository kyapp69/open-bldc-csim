#ifndef _DYN_MODEL_H
#define _DYN_MODEL_H

/* Motor parameter struct. */
struct motor {
	double inertia;  /* aka 'J' in kg/(m^2) */
	double damping;  /* aka 'B' in Nm/(rad/s) */
	double static_friction; /* in Nm */
	double Kv;       /* motor constant in RPM/V */
	double L;        /* Coil inductance in H */
	double M;        /* Mutual coil inductance in H */
	double R;        /* Coil resistence in Ohm */
	double VDC;      /* Supply voltage */
	int NbPoles;     /* NbPoles / 2 = Number of pole pairs (you count the permanent magnets on the rotor to get NbPoles) */
};

/* State vector struct. */
struct state_vector {
	double theta; /* angle of the rotor */
	double omega; /* angular speed of the rotor */
	double iu;    /* phase u current */
	double iv;    /* phase v current */
	double iw;    /* phase w current */
};

/* Command vector struct. */
struct command_vector {
	bool lu; /* high side phase U switch */
	bool hu; /* low side phase U switch */
	bool lv; /* high side phase V switch */
	bool hv; /* low side phase V switch */
	bool lw; /* high side phase W switch */
	bool hw; /* low side phase W switch */
};

/* Perturbation vector struct. */
struct perturbation_vector {
	double torque; /* Torque applied to the shaft of the motor. */
};

/* Output vector struct. */
struct output_vector {
	double iu;    /* Phase U current. */
	double iv;    /* Phase V current. */
	double iw;    /* Phase W current. */
	double vu;    /* Phase U voltage. */
	double vv;    /* Phase V voltage. */
	double vw;    /* Phase W voltage. */
	double theta; /* Rotor angle. */
	double omega; /* Rotor speed. */
};

/* Parameter struct. */
struct parameters {
	struct motor *m;
	struct command_vector *cv;
	struct perturbation_vector *pv;
};

#endif /* _DYN_MODEL_H */